# "Check Workflows" workflow (Task)

Workflow file: [check-workflows-task.yml](check-workflows-task.yml)

Validate the repository's GitHub Actions workflows against the JSON schema.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Assets

- [`Taskfile.yml`](assets/check-workflows-task/Taskfile.yml) - workflow validation task.
  - Install to: repository root (or add the `ci:validate` task into the existing `Taskfile.yml`)

## Readme badge

Markdown badge:

```markdown
[![Check Workflows status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-workflows-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-workflows-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-workflows-task.yml/badge.svg["Check Workflows status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-workflows-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to validate GitHub Actions workflows

On every push or pull request that affects the repository's GitHub Actions workflows, and periodically, validate them
against the JSON schema.
```

## PR message

```markdown
On every push or pull request that affects the repository's GitHub Actions workflows, and periodically, validate them against the JSON schema.
```
