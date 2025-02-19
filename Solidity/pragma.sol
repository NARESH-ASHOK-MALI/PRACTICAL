// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract MSW {
    address[] public owners;
    mapping(address => bool) public isOwner;
    uint256 private numConfirmationsRequired;
    uint256 private ownersLimit;
    uint256 private ownersPresent;
    uint256 private requestsWindow;
    uint256 private deployedTime;
    address private deployer;
    mapping(address => bool) public isReqOwner;

    struct Transaction {
        address to;
        uint256 value;
        bytes data;
        bool executed;
        uint256 numConfirmations;
    }

    Transaction[] public transactions;
    mapping(uint256 => mapping(address => bool)) public isConfirmed;

    event Deposit(address indexed sender, uint256 amount, uint256 balance);
    event SubmitTransaction(
        address indexed owner,
        uint256 indexed txIndex,
        address indexed to,
        uint256 value,
        bytes data
    );
    event ConfirmTransaction(address indexed owner, uint256 indexed txIndex);
    event RevokeConfirmation(address indexed owner, uint256 indexed txIndex);
    event ExecuteTransaction(address indexed owner, uint256 indexed txIndex);
    event grantedOwnership(address indexed owner, address indexed approver, uint256 timeAdded);

    modifier onlyOwner() {
        require(isOwner[msg.sender], "not owner");
        _;
    }

    modifier txExists(uint256 _txIndex) {
        require(_txIndex < transactions.length, "tx does not exist");
        _;
    }

    modifier notExecuted(uint256 _txIndex) {
        require(!transactions[_txIndex].executed, "tx already executed");
        _;
    }

    modifier notConfirmed(uint256 _txIndex) {
        require(!isConfirmed[_txIndex][msg.sender], "tx already confirmed");
        _;
    }

    constructor(
        address[] memory _owners,
        uint256 _numConfirmationsRequired,
        uint256 _ownersLimit,
        uint256 _requestsWindow
    ) {
        require(
            _numConfirmationsRequired > 0 && _numConfirmationsRequired <= _ownersLimit,
            "invalid number of required confirmations"
        );
        require(_ownersLimit > 0, "wallet needs at least one owner");
        require(_owners.length + 1 <= _ownersLimit, "invalid number of owners");

        deployedTime = block.timestamp;
        requestsWindow = _requestsWindow;
        ownersLimit = _ownersLimit;

        deployer = msg.sender;
        isOwner[msg.sender] = true;
        owners.push(msg.sender);
        ownersPresent = 1;

        for (uint256 i = 0; i < _owners.length; i++) {
            address owner = _owners[i];
            require(owner != address(0), "invalid owner");
            require(!isOwner[owner], "owner not unique");
            isOwner[owner] = true;
            owners.push(owner);
            ownersPresent += 1;
        }

        numConfirmationsRequired = _numConfirmationsRequired;
    }

    receive() external payable {
        emit Deposit(msg.sender, msg.value, address(this).balance);
    }

    function submitTransaction(address _to, uint256 _value, bytes memory _data)
        public
        onlyOwner
    {
        uint256 txIndex = transactions.length;
        transactions.push(Transaction({
            to: _to,
            value: _value,
            data: _data,
            executed: false,
            numConfirmations: 0
        }));
        emit SubmitTransaction(msg.sender, txIndex, _to, _value, _data);
    }

    function executeTransaction(uint256 _txIndex)
        public
        onlyOwner
        txExists(_txIndex)
        notExecuted(_txIndex)
    {
        Transaction storage transaction = transactions[_txIndex];
        require(
            transaction.numConfirmations >= numConfirmationsRequired,
            "cannot execute tx"
        );
        transaction.executed = true;
        (bool success,) = transaction.to.call{value: transaction.value}(transaction.data);
        require(success, "tx failed");
        emit ExecuteTransaction(msg.sender, _txIndex);
    }

    function revokeConfirmation(uint256 _txIndex)
        public
        onlyOwner
        txExists(_txIndex)
        notExecuted(_txIndex)
    {
        require(isConfirmed[_txIndex][msg.sender], "tx not confirmed");
        isConfirmed[_txIndex][msg.sender] = false;
        transactions[_txIndex].numConfirmations -= 1;
        emit RevokeConfirmation(msg.sender, _txIndex);
    }

    function requestOwnership() public returns (uint256) {
        require(!isOwner[msg.sender], "already an owner");
        require(!isReqOwner[msg.sender], "already requested owner access");
        require(ownersPresent + 1 <= ownersLimit, "owners limit reached");
        require(block.timestamp <= deployedTime + requestsWindow, "requesting window closed");
        isReqOwner[msg.sender] = true;
        return (block.timestamp - deployedTime);
    }

    function grantOwnership(address _addowner) 
    public 
    onlyOwner 
    {
        require(isReqOwner[_addowner], "did not request owner access");
        require(ownersPresent + 1 <= ownersLimit, "owners limit reached");
        require(!isOwner[_addowner], "owner not unique");
        require(_addowner != address(0), "invalid owner");
        isOwner[_addowner] = true;
        owners.push(_addowner);
        ownersPresent += 1;
        emit grantedOwnership(_addowner, msg.sender, block.timestamp);
    }

    function getOwners() public view returns (address[] memory) {
        return owners;
    }

    function getTransactionCount() public view returns (uint256) {
        return transactions.length;
    }

    function getTransaction(uint256 _txIndex)
        public
        view
        returns (
            address to,
            uint256 value,
            bytes memory data,
            bool executed,
            uint256 numConfirmations
        )
    {
        Transaction storage transaction = transactions[_txIndex];
        return (
            transaction.to,
            transaction.value,
            transaction.data,
            transaction.executed,
            transaction.numConfirmations
        );
    }

    function getBalance() external view onlyOwner returns (uint256) {
        return address(this).balance;
    }
}