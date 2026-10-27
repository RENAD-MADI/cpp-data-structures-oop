# C++ Data Structures & OOP

![Build](https://github.com/RENAD-MADI/cpp-data-structures-oop/actions/workflows/build.yml/badge.svg)
![C++20](https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white)

<div dir="rtl">

مشاريع C++ جامعية في هياكل البيانات (Linked List وStack وQueue) والبرمجة كائنية التوجه (الوراثة، تعدد الأشكال، الكلاسات المجردة).

</div>

University C++ projects on data structures (CS231) and object-oriented programming. Every program is compiled on each push by GitHub Actions.

## Projects

### Pharmacy management system — `pharmacy-management/`
A console system for a pharmacy chain: branches, drugs, pharmacists and customers, with add / search / update / delete menus. Implemented three times on hand-written data structures:

| File | Data structure |
|---|---|
| `1-linked-list.cpp` | Singly linked lists (`DrugList`, `PharmacistList`, `CustomerList`, `BranchList`) |
| `2-stack.cpp` | Stacks (LIFO) |
| `3-queue.cpp` | Queues (FIFO) |

### Restaurant system — `restaurant-system/`
Food items, stock, branches, menus and customers modelled with classes and `std::vector` (`main.cpp`).

### OOP exercises — `oop/`
| Folder | Concepts |
|---|---|
| `cars/` | Inheritance and `virtual` / `override` (`Car` → `EV`), separate headers and sources |
| `employees/` | Base and derived classes (`Person` → `Employee`), input validation |
| `shapes/` | Abstract base class and pure virtual functions (`Shape` → `Square`, `Rectangle`, `Circle`), `std::numbers::pi` |

## Build and run

```bash
g++ -std=c++20 -o pharmacy pharmacy-management/1-linked-list.cpp && ./pharmacy
g++ -std=c++20 -o restaurant restaurant-system/main.cpp && ./restaurant
g++ -std=c++20 -o cars oop/cars/*.cpp && ./cars
g++ -std=c++20 -o shapes oop/shapes/shape_main.cpp && ./shapes
```

## Author

**Renad Madi** — [GitHub](https://github.com/RENAD-MADI)
