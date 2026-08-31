# COS214 Event Management System

## Event Concept

**COS214 Lentedag** is an event management system designed to organize and manage various components of a large-scale music festival. The system uses the **Composite Design Pattern** to create a hierarchical structure of event components, allowing for unified management of both individual elements and groups.

### Key Features
- **Composite Pattern**: Hierarchical organization of event components
- **Capacity Management**: Track and manage venue capacities
- **Weather Response**: Automated responses to weather warnings
- **Emergency Handling**: Medical and evacuation coordination
- **Flexible Architecture**: Add/remove components dynamically
- **Observer Pattern**: Event notifications and responses

### Components
| Component Type | Description | Examples |
|---------------|-------------|----------|
| **EventGroup** | Composite nodes that can contain children | Music Festival, Entertainment Zone|
| **EventUnit** | Leaf nodes with no children | Main Stage, Food Court, Medical Center |

---

## Team Members

| Name | Student Number |
|------|---------------|
| **Anchen Kruger** | [25073703#] | 
| **Caleb Jennings** | [Student#] | 
| **Chloe Larsen** | [Student#] | 

---

## Main settings changed within DoxygenFile

```bash
PROJECT_NAME           = "COS214 Event Management System"
OUTPUT_DIRECTORY       = ./docs
INPUT                  = ./include ./src
RECURSIVE              = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES
GENERATE_HTML          = YES
GENERATE_TREEVIEW      = YES
SOURCE_BROWSER         = YES
HAVE_DOT               = YES  # Requires Graphviz

```

### How to use it:

```bash

# Or manually
doxygen Doxyfile

# View documentation
make view-docs

# Or manually open in browser
# Windows: start docs/html/index.html
# Mac: open docs/html/index.html
# Linux: firefox docs/html/index.html

```

### Formalities on the documentation: 

```bash

/**
 * @brief Brief description
 * @param param_name Description
 * @return Description of return value
 */
void methodName(int param_name);

/**
 * @class ClassName
 * @brief Brief class description
 * 
 * Detailed class description.
 */
class ClassName {
    int member; ///< Member description
};

```

---

## Building with Make

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

```