<!-- Source: https://github.com/arduino/tooling-project-assets/blob/main/documentation-templates/contributor-guide/task/development.md -->

# Development Guide

## Prerequisites

The following development tools must be available in your local environment:

<!-- TODO: add all other tools which are not installed automatically (e.g., Go, Node.js, Python, Poetry) -->

- [**Task**](https://taskfile.dev/installation/) - task runner tool

## Building the Project

---

**ⓘ** If you only want to test an existing version of the project, automatically generated builds are available for download without building from source. See the instructions in the [**beta testing guide**](contributor-guide/beta-testing.md#beta-testing-guide).

---

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
