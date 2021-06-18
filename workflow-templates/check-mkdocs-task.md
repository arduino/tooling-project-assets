# "Check Website" workflow (MkDocs, Task)

Workflow file: [check-mkdocs-task.yml](check-mkdocs-task.yml)

Check for problems with a [MkDocs](https://www.mkdocs.org/)-based static website.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

See [the "Deploy Website" (MkDocs, Poetry) workflow documentation](deploy-mkdocs-poetry.md#installation)

## Assets

- [`Taskfile.yml`](assets/check-yaml-task/Taskfile.yml) - Build task.
  - Install to: repository root (or add the `website:build` task into the existing `Taskfile.yml`)
- [`Taskfile.yml`](assets/shared/Taskfile.yml) - Installation task.
  - Add the `poetry:install-deps` task into the existing `Taskfile.yml`
- Website assets - See [the "Deploy Website" (MkDocs, Poetry) workflow documentation](deploy-mkdocs-poetry.md#assets).

## Readme badge

Markdown badge:

```markdown
[![Check Website status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-mkdocs-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-mkdocs-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

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
