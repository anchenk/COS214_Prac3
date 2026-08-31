# COS214 Event Management System

## Event Concept

**COS214 Summer Music Festival** is an event management system designed to organize and manage various components of a large-scale music festival. The system uses the **Composite Design Pattern** to create a hierarchical structure of event components, allowing for unified management of both individual elements and groups.

### Key Features
- 🎭 **Composite Pattern**: Hierarchical organization of event components
- 📊 **Capacity Management**: Track and manage venue capacities
- 🌦️ **Weather Response**: Automated responses to weather warnings
- 🚑 **Emergency Handling**: Medical and evacuation coordination
- 🏗️ **Flexible Architecture**: Add/remove components dynamically
- 📝 **Observer Pattern**: Event notifications and responses

### Components
| Component Type | Description | Examples |
|---------------|-------------|----------|
| **EventGroup** | Composite nodes that can contain children | Music Festival, Entertainment Zone|
| **EventUnit** | Leaf nodes with no children | Main Stage, Food Court, Medical Center |

---

## Team Members

| **Anchen Kruger** | [25073703#] | 
| **Caleb Jennings** | [Student#] | 
| **Chloe Larsen** | [Student#] | 

---

## Building with Make

### Prerequisites
- **C++ Compiler**: g++ 7.0+ or clang 10.0+
- **Make**: GNU Make 3.81+
- **Doxygen**: For documentation generation (optional)
- **Graphviz**: For diagrams (optional)

### Build Instructions

```bash

# Build the project
make

# Run the executable
make run

# Clean build artifacts
make clean

# Build with debug symbols
make debug

# Generate documentation
make docs

# View documentation
make view-docs

# Or manually
doxygen Doxyfile

# View documentation
make view-docs

# Or manually open in browser
# Windows: start docs/html/index.html
# Mac: open docs/html/index.html
# Linux: firefox docs/html/index.html