n = int(input("Enter number of employees: "))
salaries = []

for i in range(n):
    salary = float(input(f"Enter salary of employee {i + 1}: "))
    salaries.append(salary)
print("\nOriginal salaries:", salaries)

selection = salaries.copy()
for i in range(n - 1):
    minpos = i
    for j in range(i + 1, n):
        if selection[j] < selection[minpos]:
            minpos = j
    selection[i], selection[minpos] = selection[minpos], selection[i]

print("Salaries after Selection Sort:", selection)

bubble = salaries.copy()
for i in range(n - 1):
    for j in range(n - 1 - i):
        if bubble[j] > bubble[j + 1]:
            bubble[j], bubble[j + 1] = bubble[j + 1], bubble[j]

print("Salaries after Bubble Sort:", bubble)

print("\nTop 5 highest salaries:");
top = min(5, n)
for i in range(n-1, n-top-1, -1):
    print(bubble[i])
