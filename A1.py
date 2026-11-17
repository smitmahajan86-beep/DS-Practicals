n = int(input("Enter number of library members: "))
books = []

for i in range(n):
    count = int(input(f"Enter number of books borrowed by member {i + 1}: "))
    books.append(count)
print("\nBorrowing records:",books)


print("Average:", sum(books) / len(books))
print("Zero borrowing members:", books.count(0))

highest = max(books)
lowest = min(books)

print("Highest number of books borrowed:", highest)
print("Lowest number of books borrowed:", lowest)