# "Check YAML" workflow (Task)

Run [yamllint](https://github.com/adrienverge/yamllint) on the YAML files of the repository.

NOTE: This workflow is focused on linting. Formatting checks for YAML are provided by the ["Check Prettier Formatting" workflow](check-prettier-formatting-task.md), so both should be used.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [check-yaml-task.yml](check-yaml-task.yml) GitHub Actions workflow to `.github/workflows/`

## Assets

- [`.yamllint.yml`](assets/check-yaml/.yamllint.yml) - `yamllint` configuration file.
  - Install to: repository root
- [`Taskfile.yml`](assets/check-yaml-task/Taskfile.yml) - Linting task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`

The code style defined in this file is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Dependencies

The `yamllint` tool dependency is managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="yamllint@^1.31.0"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "yamllint@^1.31.0"
```

Commit the resulting `pyproject.toml` and `poetry.lock` files.

### Configuration

If the repository contains generated or vendored files, they can be excluded from the check by adding them to the `ignore` field in the `.yamllint.yml` configuration file.

Reference:
https://yamllint.readthedocs.io/en/stable/configuration.html

### Readme badge

Markdown badge:

```markdown
[![Check YAML status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-yaml-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-yaml-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-yaml-task.yml/badge.svg["Check YAML status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-yaml-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to lint YAML files

On every push and pull request that affects relevant files, run yamllint to check the YAML files of
the repository for issues.

The .yamllint.yml file is used to configure yamllint:
https://yamllint.readthedocs.io/en/stable/configuration.html
```

## PR message

```markdown
On every push and pull request that affects relevant files, run [`yamllint`](https://github.com/adrienverge/yamllint) to check the YAML files of the repository for issues.

The `.yamllint.yml` file is used to configure `yamllint`:
https://yamllint.readthedocs.io/en/stable/configuration.html
```
