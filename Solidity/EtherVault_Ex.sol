// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract BasicDeFi {
    // Data structure to store user balances
    struct User {
        uint256 depositBalance; // User's deposited balance
        uint256 borrowBalance; // User's borrowed balance
    }

    mapping(address => User) public users; // Mapping of user addresses to their account details
    uint256 public totalDeposits; // Total Ether deposited in the contract
    uint256 public totalBorrows; // Total Ether borrowed from the contract
    uint256 public constant interestRate = 5; // 5% annual interest rate

    // Events for logging contract activities
    event Deposited(address indexed user, uint256 amount);
    event Withdrawn(address indexed user, uint256 amount);
    event Borrowed(address indexed user, uint256 amount);
    event Repaid(address indexed user, uint256 amount);

    // Function to deposit Ether into the contract
    function deposit() external payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");

        // Update user's deposit balance
        users[msg.sender].depositBalance += msg.value;

        // Update total deposits
        totalDeposits += msg.value;

        emit Deposited(msg.sender, msg.value);
    }

    // Function to withdraw Ether from the contract
    function withdraw(uint256 amount) external {
        require(amount > 0, "Withdrawal amount must be greater than 0");
        require(users[msg.sender].depositBalance >= amount, "Insufficient deposit balance");

        // Update user's deposit balance
        users[msg.sender].depositBalance -= amount;

        // Update total deposits
        totalDeposits -= amount;

        // Transfer Ether back to the user
        payable(msg.sender).transfer(amount);

        emit Withdrawn(msg.sender, amount);
    }

    // Function to borrow Ether against collateral
    function borrow(uint256 amount) external {
        require(amount > 0, "Borrow amount must be greater than 0");
        require(users[msg.sender].depositBalance >= amount, "Insufficient collateral");

        // Update user's borrow balance
        users[msg.sender].borrowBalance += amount;

        // Update total borrows
        totalBorrows += amount;

        // Transfer borrowed Ether to the user
        payable(msg.sender).transfer(amount);

        emit Borrowed(msg.sender, amount);
    }

    // Function to repay borrowed Ether
    function repay() external payable {
        require(msg.value > 0, "Repayment amount must be greater than 0");
        require(users[msg.sender].borrowBalance >= msg.value, "Repayment amount exceeds borrow balance");

        // Update user's borrow balance
        users[msg.sender].borrowBalance -= msg.value;

        // Update total borrows
        totalBorrows -= msg.value;

        emit Repaid(msg.sender, msg.value);
    }

    // Function to calculate interest earned on deposits
    function calculateInterest(address user) public view returns (uint256) {
        // Calculate interest based on the user's deposit balance and the annual interest rate
        return (users[user].depositBalance * interestRate) / 100;
    }

    // Function to get the account details of a user
    function getAccountDetails(address user) external view returns (uint256 depositBalance, uint256 borrowBalance, uint256 interestEarned) {
        depositBalance = users[user].depositBalance;
        borrowBalance = users[user].borrowBalance;
        interestEarned = calculateInterest(user);
    }
}