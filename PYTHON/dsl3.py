# Define the list of books
print("User is HITESH SANJAY KHARE\nSCOD19")
books = [
    {"title": "book1", "cost": 999},
    {"title": "book2", "cost": 450},
    {"title": "book1", "cost": 999},
    {"title": "book3", "cost": 399},
    {"title": "book4", "cost": 499},
    {"title": "book5", "cost": 599}
]

def deleting_duplicate_entries(books):
    unique_titles = set()
    unique_books = []
   
    for book in books:
        if book["title"] not in unique_titles:
            unique_titles.add(book["title"])
            unique_books.append(book)
    return unique_books

def bubble_sort_books_by_cost(books):
    n = len(books)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if books[j]['cost'] > books[j + 1]['cost']:
                books[j], books[j + 1] = books[j + 1], books[j]
                swapped = True
        if not swapped:
            break

def display_books_sorted_by_cost(books):
    bubble_sort_books_by_cost(books)
    for book in books:
        print(f"Title: {book['title']}, Cost: {book['cost']}")
def count_books_with_cost_above(books, threshold):
    count = 0
    for book in books:
        if book['cost'] > threshold:
            count += 1
    print("number of books with cost more than",threshold,"are",count)
def copy_books_with_cost_below(books, threshold):
    new_list = [book for book in books if book['cost'] < threshold]
    bk=new_list
    print("Copying books in a new list which has cost less than", threshold, "\n")
   
    print(new_list)


unique_books = deleting_duplicate_entries(books)
print("Books after removing duplicates:")
for book in unique_books:
    print(book)
print(" ")
print("Displaying books in ascending order based on cost of books")
print(" ")
display_books_sorted_by_cost(books)
print(" ")
count_books_with_cost_above(books,500)
print(" ")
copy_books_with_cost_below(books, 500)

   