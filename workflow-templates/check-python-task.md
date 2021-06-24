# "Check Python" workflow (Task)

Workflow file: [`check-python-task.yml`](check-python-task.yml)

Run [flake8](https://flake8.pycqa.org/) and [black](https://github.com/psf/black) on the Python files of the repository.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### 1. Add configuration files

Copy the configuration files listed in the [**Assets**](#assets) section below into the project's repository.

If the project already contains a [`pyproject.toml`](https://www.python.org/dev/peps/pep-0518/) file, then merge them.

### 2. Install tool dependencies

The tool dependencies of this workflow are managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="black@^21.5b0" --dev-dependency="flake8@^3.9.2" --dev-dependency="pep8-naming@^0.11.1"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "black@^21.5b0" "flake8@^3.9.2" "pep8-naming@^0.11.1"
```

Make sure to commit the resulting `pyproject.toml` and `poetry.lock` files.

### 3. Configuration

Add the following to `pyproject.toml`:

```toml
[tool.black]
line-length = 120
```

## Assets

- [`.flake8`](assets/check-python/.flake8) - flake8 configuration file.
  - Install to: repository root
- [`Taskfile.yml`](assets/check-python-task/Taskfile.yml) - Python linting and formatting tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/shared/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`

The code style defined in `pyproject.toml` and `.flake8` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

## Readme badge

Markdown badge:

```markdown
[![Check Python status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-python-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-python-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-python-task.yml/badge.svg["Check Python status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-python-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to lint and check formatting of Python files

On every push and pull request that affects relevant files, run flake8 to check the Python files of
the repository for issues and black to check formatting.

The .flake8 file is used to configure flake8:
https://flake8.pycqa.org/en/latest/user/configuration.html
```

## PR message

```markdown
On every push and pull request that affects relevant files, run [`flake8`](https://flake8.pycqa.org/) to check the Python files of the repository for issues and [black](https://github.com/psf/black) to check formatting.

The `.flake8` file is used to configure `flake8`:
https://flake8.pycqa.org/en/latest/user/configuration.html
```
