# "Check YAML" workflow (Task)

Workflow file: [check-yaml-task.yml](check-yaml-task.yml)

Run [yamllint](https://github.com/adrienverge/yamllint) on the YAML files of the repository.

NOTE: This workflow is focused on linting. Formatting checks for YAML are provided by the ["Check Prettier Formatting" workflow](check-prettier-formatting-task.md), so both should be used.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

The `yamllint` tool dependency is managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="yamllint@^1.26.1"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "yamllint@^1.26.1"
```

Make sure to commit the resulting `pyproject.toml` and `poetry.lock` files.

## Assets

- [.yamllint.yml](assets/check-yaml/.yamllint.yml) - `yamllint` [configuration file](https://yamllint.readthedocs.io/en/stable/configuration.html).
  - Install to: repository root
- [`Taskfile.yml`](assets/check-yaml-task/Taskfile.yml) - Linting task.
  - Install to: repository root (or add the `yaml:lint` task into the existing `Taskfile.yml`)
- [`Taskfile.yml`](assets/shared/Taskfile.yml) - Installation task.
  - Add the `poetry:install-deps` task into the existing `Taskfile.yml`

The code style defined in this file is the official standardized style to be used in all Arduino projects and should not be modified.

## Readme badge

Markdown badge:

```markdown
[![Check YAML status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-yaml-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-yaml-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

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
