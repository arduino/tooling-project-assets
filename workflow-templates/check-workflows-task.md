# "Check Workflows" workflow (Task)

Validate the repository's GitHub Actions workflows against the JSON schema.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-workflows-task.yml`](check-workflows-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.npmrc`](assets/npm/.npmrc) - **npm** configuration file.
  - Install to: repository root.
- [`Taskfile.yml`](assets/check-workflows-task/Taskfile.yml) - workflow validation task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/windows-task/Taskfile.yml) - Utility tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Dependencies

The tool dependencies of this workflow are managed by [npm](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev ajv-cli@^5.0.0 ajv-formats@^3.0.1
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### `.gitignore`

Add the following to [`/.gitignore`](https://git-scm.com/docs/gitignore):

```
/node_modules/
```

#### Node.js

Configure the version of [**Node.js**](https://nodejs.org) used for development of the project by running the following command from a terminal in the project repository folder:

```text
npm pkg set engines.node=22.x
```

### Readme badge

Markdown badge:

```markdown
[![Check Workflows status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-workflows-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-workflows-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-workflows-task.yml/badge.svg["Check Workflows status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-workflows-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to validate GitHub Actions workflows

A task is provided to check for problems in the project's GitHub Actions workflows by validating them against the JSON
schema.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
A task is provided to check for problems in the project's GitHub Actions workflows by validating them against [the JSON schema](https://json.schemastore.org/github-workflow).

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```
