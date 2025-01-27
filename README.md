# Olympics Management System

## Overview
This project is a data structures-based system for managing participants, teams, and countries in a simulated Olympics competition. The system supports efficient operations for adding, removing, and managing entities while ensuring optimal performance.

## Features

### Core Functionalities
- **Country Management**:
  - Add or remove countries with unique IDs and medal counts.
- **Team Management**:
  - Add or remove teams associated with specific countries and sports.
  - Merge teams within the same sport and country.
- **Contestant Management**:
  - Add or remove contestants with unique IDs, strength, and sports.
  - Assign contestants to teams with appropriate validations.
- **Competitions**:
  - Simulate matches between teams and update results dynamically.
  - Retrieve team or contestant strengths.
- **Optimization**:
  - Calculate maximum team strength after reducing the number of contestants.

### Additional Features
- Error handling for invalid inputs and allocation issues.
- Custom memory-efficient data structures.
- Complexity guarantees for all operations.

---

## File Structure

### Core Files
- **`main24a1.cpp`**: Entry point of the program. Processes input commands and initializes the system.
- **`olympics24a1.h` / `olympics24a1.cpp`**: Contains core data structures and logic for country, team, and contestant management.
- **`wet1util.h`**: Utility functions for error handling and standardized output.

### Supporting Files
- **Test Files**:
  - **`input.txt`**: Sample input commands for testing the system.
  - **`output.txt`**: Expected output for verification.

---

## How to Build

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd project_directory
   ```
2. Compile the program:
   ```bash
   g++ -std=c++11 -o olympics -Wall -pedantic-errors -Werror -DNDEBUG *.cpp
   ```

---

## How to Run

1. Run the executable:
   ```bash
   ./olympics
   ```
2. Use interactive commands to manage the system, or redirect an input file:
   ```bash
   ./olympics < input.txt
   ```

---

## Commands

### Adding a Country
```bash
add_country <country_id> <medal_count>
```
Example:
```bash
add_country 1 5
```
Adds a country with ID 1 and 5 medals.

### Adding a Team
```bash
add_team <team_id> <country_id> <sport>
```
Example:
```bash
add_team 10 1 BOULDERING
```
Adds a team with ID 10 for country 1 in the sport of bouldering.

### Adding a Contestant
```bash
add_contestant <contestant_id> <country_id> <sport> <strength>
```
Example:
```bash
add_contestant 100 1 BOULDERING 50
```
Adds contestant 100 to country 1 in the sport of bouldering with a strength of 50.

### Simulating a Match
```bash
play_match <team_id_1> <team_id_2>
```
Example:
```bash
play_match 10 20
```
Simulates a match between teams 10 and 20.

---

## Testing

### Run Tests
1. Create a test input file (e.g., `input.txt`):
   ```text
   add_country 1 5
   add_team 10 1 BOULDERING
   add_contestant 100 1 BOULDERING 50
   add_contestant_to_team 10 100
   play_match 10 20
   ```
2. Execute the program with the test file:
   ```bash
   ./olympics < input.txt > output.txt
   ```
3. Compare `output.txt` with the expected results.

### Memory Management
Run the program with `valgrind` to detect memory leaks:
```bash
valgrind --leak-check=full ./olympics
```

---

## Error Handling
- **Invalid Inputs**:
  - Outputs an error message and continues operation.
- **Deck Errors**:
  - Handles file not found, invalid format, or invalid size errors.

### Example Errors
- `Deck File Error: File not found`
- `Deck File Error: File format error in line <lineNumber>`
- `Deck File Error: Deck size is invalid`

---

## Good Practices
- **Modular Design**:
  - Each operation is handled independently for better extensibility.
- **Memory Management**:
  - Ensure no memory leaks by using smart pointers and proper cleanup.
- **Error Handling**:
  - Handle edge cases and invalid operations gracefully.

---

## Conclusion
This Olympics Management System demonstrates efficient use of custom data structures to handle complex operations in a scalable and optimized way. It is designed with clean coding practices, making it robust and extensible for future enhancements.
