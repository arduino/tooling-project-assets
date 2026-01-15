# "Check Website" workflow (MkDocs, Task)

Check for problems with a [MkDocs](https://www.mkdocs.org/)-based static website.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-mkdocs-task.yml`](check-mkdocs-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`pyproject.toml`](assets/poetry/pyproject.toml) - [**Poetry**](https://python-poetry.org/) configuration.
  - Install to: repository root (unless a `pyproject.toml` file is already present).
- [`Taskfile.yml`](assets/check-mkdocs-task/Taskfile.yml) - Build task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`
- [`Taskfile.yml`](assets/windows-task/Taskfile.yml) - Utility tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`.gitignore`](assets/check-mkdocs-task/.gitignore)
  - Install to: repository root (or merge into the existing `.gitignore`).
- Website assets - See [the "Deploy Website" (MkDocs, Poetry) workflow documentation](deploy-mkdocs-poetry.md#assets).

### Dependencies

See [the "Deploy Website" (MkDocs, Poetry) workflow documentation](deploy-mkdocs-poetry.md#dependencies)

### Configuration

#### Taskfile

Add any documentation generation processes to the `docs:generate` umbrella task.

#### MkDocs

See [the "Deploy Website" (MkDocs, Poetry) workflow documentation](deploy-mkdocs-poetry.md#configuration)

### Readme badge

Markdown badge:

```markdown
[![Check Website status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-mkdocs-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-mkdocs-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-mkdocs-task.yml/badge.svg["Check Website status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-mkdocs-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check for problems with MkDocs-based website

On every push or pull request that affects the source and configuration for the repository's MkDocs-based static
website, build the site and fail if any problems were encountered.
```

## PR message

```markdown
On every push or pull request that affects the source and configuration for the repository's [MkDocs](https://www.mkdocs.org/)-based static website, build the site and fail if any problems were encountered.
```
