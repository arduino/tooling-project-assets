# "Check Python" workflow (Task)

Run [flake8](https://flake8.pycqa.org/) and [black](https://github.com/psf/black) on the Python files of the repository.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-python-task.yml`](check-python-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.flake8`](assets/check-python/.flake8) - flake8 configuration file.
  - Install to: repository root
- [`Taskfile.yml`](assets/check-python-task/Taskfile.yml) - Python linting and formatting tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`

The code style defined in `pyproject.toml` and `.flake8` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Dependencies

The tool dependencies of this workflow are managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="black@^24.2.0" --dev-dependency="flake8@^7.0.0" --dev-dependency="pep8-naming@^0.13.3"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "black@^24.2.0" "flake8@^7.0.0" "pep8-naming@^0.13.3"
```

Commit the resulting `pyproject.toml` and `poetry.lock` files.

### Configuration

#### Workflow

Set the version of Python used by the project in the `env.PYTHON_VERSION` field of `check-python-task.yml`.

#### black

Add the following to `pyproject.toml`:

```toml
[tool.black]
line-length = 120
```

The `black` configuration is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Readme badge

Markdown badge:

```markdown
[![Check Python status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-python-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-python-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

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
