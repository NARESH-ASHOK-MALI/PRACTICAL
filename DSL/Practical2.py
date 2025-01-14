'''In second year computer engineering class, group A student’s play cricket, group B students play
 badminton and group C students play football.
 Write a Python program using functions to compute following:
List of students who play both cricket and badminton
 List of students who play either cricket or badminton but not both
 Number of students who play neither cricket nor badminton
 Number of students who play cricket and football but not badminton.'''
# Define sets of students for each sport
def get_data():
    cricket = {"Alice", "Bob", "Charlie", "David"}
    badminton = {"Bob", "Eve", "Charlie", "Frank"}
    football = {"David", "George", "Harry", "Alice"}
    all_students = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "George", "Harry", "Irene", "John"}
    return cricket, badminton, football, all_students

# List of students who play both cricket and badminton
def play_both_cricket_and_badminton(cricket, badminton):
    return cricket & badminton

# List of students who play either cricket or badminton but not both
def play_either_cricket_or_badminton_but_not_both(cricket, badminton):
    return (cricket | badminton) - (cricket & badminton)

# Number of students who play neither cricket nor badminton
def play_neither_cricket_nor_badminton(cricket, badminton, all_students):
    return len(all_students - (cricket | badminton))

# Number of students who play cricket and football but not badminton
def play_cricket_and_football_but_not_badminton(cricket, football, badminton):
    return len((cricket & football) - badminton)

# Main function to compute and print results
def main():
    cricket, badminton, football, all_students = get_data()
    
    both_cricket_and_badminton = play_both_cricket_and_badminton(cricket, badminton)
    either_cricket_or_badminton_but_not_both = play_either_cricket_or_badminton_but_not_both(cricket, badminton)
    neither_cricket_nor_badminton_count = play_neither_cricket_nor_badminton(cricket, badminton, all_students)
    cricket_and_football_but_not_badminton_count = play_cricket_and_football_but_not_badminton(cricket, football, badminton)
    
    print("Students who play both cricket and badminton:", both_cricket_and_badminton)
    print("Students who play either cricket or badminton but not both:", either_cricket_or_badminton_but_not_both)
    print("Number of students who play neither cricket nor badminton:", neither_cricket_nor_badminton_count)
    print("Number of students who play cricket and football but not badminton:", cricket_and_football_but_not_badminton_count)

# Run the program
if __name__ == "__main__":
    main()
