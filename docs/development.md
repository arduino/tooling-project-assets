<!-- Source: https://github.com/arduino/tooling-project-assets/blob/main/documentation-templates/contributor-guide/task/development.md -->

# Development Guide

## Prerequisites

The following development tools must be available in your local environment:

- [**Go**](https://go.dev/dl/) - programming language
  - The **Go** version in use is defined in the `go` directive of [`go.mod`](../go.mod).
  - [**gvm**](https://github.com/moovweb/gvm#installing) is recommended if you want to manage multiple installations of **Go** on your system.
- [**Node.js** / **npm**](https://nodejs.org/en/download/) - Node.js dependencies management tool
  - The **Node.js** version in use is defined by the `engines.node` key of [`package.json`](../package.json).
- [**Python**](https://wiki.python.org/moin/BeginnersGuide/Download)
  - The **Python** version in use is defined by the `tool.poetry.dependencies.python` key of [`pyproject.toml`](../pyproject.toml).
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
