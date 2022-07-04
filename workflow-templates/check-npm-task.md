# "Check npm" workflow (Task)

Check for problems with configuration files of the [npm](https://www.npmjs.com/) JavaScript package manager.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [check-npm-task.yml](check-npm-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/check-npm-task/Taskfile.yml) - Validation task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/windows-task/Taskfile.yml) - Utility tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Configuration

Configure the version of Node.js used for development of the project in the `env.NODE_VERSION` field of `check-npm-task.yml`.

## Readme badge

Markdown badge:

```markdown
[![Check npm status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-npm-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-npm-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-npm-task.yml/badge.svg["Check YAML status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-npm-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check for problems with npm configuration files

On every push and pull request that affects relevant files, and periodically:

- Validate package.json against its JSON schema.
- Check for forgotten package-lock.json syncs.
```

## PR message

```markdown
On every push and pull request that affects relevant files, and periodically:

- Validate [`package.json`](https://docs.npmjs.com/cli/v7/configuring-npm/package-json) against [its JSON schema](https://json.schemastore.org/package.json).
- Check for forgotten [`package-lock.json`](https://docs.npmjs.com/cli/v7/configuring-npm/package-lock-json) syncs.
```
