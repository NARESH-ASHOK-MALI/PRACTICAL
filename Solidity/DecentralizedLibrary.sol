
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract DecentralizedLibrary {

    // *** BASIC TYPES ***
    address public owner; // Address type for the contract owner
    uint public bookCount; // Unsigned integer to track total books
    bool public isLibraryOpen; // Boolean to indicate library status
    string public libraryName;

    // *** ENUM ***
    enum BookStatus { Available, Borrowed, Reserved } // Enum to track book status

    // *** STRUCT ***
    struct Book {
        uint id;
        string title;
        address borrower; // Address of the borrower
        BookStatus status; // Enum to indicate status
    }

    // *** ARRAY AND MAPPING ***
    mapping(uint => Book) public books; // Mapping of book IDs to Book struct
    uint[] public availableBooks; // Dynamic array of available book IDs

    // *** EVENTS ***
    event BookAdded(uint bookId, string title); // Event for adding a book
    event BookBorrowed(uint bookId, address borrower); // Event for borrowing a book
    event BookReturned(uint bookId, address borrower); // Event for returning a book

    // *** MODIFIERS ***
    modifier onlyWhenLibraryOpen() {
        require(isLibraryOpen, "The library is closed");
        _;
    }
    
    // *** MODIFIERS ***
    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can perform this action");
        _;
    }

    // *** CONSTRUCTOR ***
    constructor(string memory _libraryName) {
        owner = msg.sender; // Set the contract deployer as the owner
        libraryName = _libraryName; // Set the library name
        isLibraryOpen = true; // Open the library by default
    }

    // *** FUNCTIONS ***

    // Add a new book to the library
    function addBook(string memory _title) public onlyOwner {
        bookCount++;
        books[bookCount] = Book(bookCount, _title, address(0), BookStatus.Available);
        availableBooks.push(bookCount);
        emit BookAdded(bookCount, _title);
    }

    // Borrow a book from the library
    function borrowBook(uint _bookId) public onlyWhenLibraryOpen {
        Book storage book = books[_bookId];
        require(book.status == BookStatus.Available, "Book is not available");
        book.borrower = msg.sender;
        book.status = BookStatus.Borrowed;

        // Remove from availableBooks array
        _removeFromAvailableBooks(_bookId);

        emit BookBorrowed(_bookId, msg.sender);
    }

    // Return a book to the library
    function returnBook(uint _bookId) public onlyWhenLibraryOpen {
        Book storage book = books[_bookId];
        require(book.borrower == msg.sender, "You are not the borrower of this book");
        book.borrower = address(0);
        book.status = BookStatus.Available;
        availableBooks.push(_bookId); // Add back to availableBooks array
        emit BookReturned(_bookId, msg.sender);
    }

    // Get details of a book by its ID
    function getBookDetails(uint _bookId) public view returns (string memory, address, BookStatus) {
        Book storage book = books[_bookId];
        return (book.title, book.borrower, book.status);
    }

    // Toggle the library open/closed status
    function toggleLibraryStatus() public onlyOwner {
        isLibraryOpen = !isLibraryOpen;
    }

    // Internal function to remove a book from availableBooks array
    function _removeFromAvailableBooks(uint _bookId) internal {
        for (uint i = 0; i < availableBooks.length; i++) {
            if (availableBooks[i] == _bookId) {
                availableBooks[i] = availableBooks[availableBooks.length - 1];
                availableBooks.pop();
                break;
            }
        }
    }
}


