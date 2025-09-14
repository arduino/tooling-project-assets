# Poetry Assets

Python package dependencies are managed using the [**Poetry**](https://python-poetry.org/) tool.

In addition to direct dependencies used by project Python code, **Poetry** is also used to manage Python package-based tools that are used for development and maintenance operations in the project.

## Installation

### Assets

Install [`pyproject.toml`](pyproject.toml) to the root of the project repository.

## Configuration

### If the project is not a Python package

No configuration is needed.

### If the project is a Python package

1. Delete the following line from the `pyproject.toml` file:
   ```toml
   package-mode = false
   ```
1. Add a `build-system` section to the `pyproject.toml` file:<br />
   https://python-poetry.org/docs/pyproject/#poetry-and-pep-517
1. Define the package metadata under the `tool.poetry` section of the `pyproject.toml` file:<br />
   https://python-poetry.org/docs/pyproject#the-toolpoetry-section
