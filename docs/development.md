<!-- Source: https://github.com/arduino/tooling-project-assets/blob/main/documentation-templates/contributor-guide/task/development.md -->

# Development Guide

## Prerequisites

The following development tools must be available in your local environment:

- [**Node.js** / **npm**](https://nodejs.org/en/download/) - Node.js dependencies management tool
  - <!-- NODE_VERSION -->
    This project uses Node.js 16.x
- [**Python**](https://wiki.python.org/moin/BeginnersGuide/Download)
  - <!-- PYTHON_VERSION -->
    This project uses Python 3.9.x
- [**Poetry**](https://python-poetry.org/docs/#installation) - Python dependencies management tool
- [**Task**](https://taskfile.dev/installation/) - task runner tool

## Building the Project

You can build the project by running this command from the root folder of the project:

```text
task build
```

## Running Checks

Checks and tests are set up to ensure the project content is functional and compliant with the established standards.

You can run the checks by running this command from the root folder of the project:

```text
task check
```

## Automatic Corrections

Tools are provided to automatically bring the project into compliance with some of the required checks.

You can make these automatic fixes by running this command from the root folder of the project:

```text
task fix
```
