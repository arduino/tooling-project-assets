# "Check Action Metadata" workflow (Task)

Validate the [`action.yml`](https://docs.github.com/en/actions/creating-actions/metadata-syntax-for-github-actions) GitHub Actions action metadata file against its JSON schema.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-action-metadata-task.yml`](check-action-metadata-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/check-action-metadata-task/Taskfile.yml] - task for validating `action.yml`
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - **npm** tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Dependencies

The tool dependencies of this workflow are managed by [**npm**](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev ajv-cli@^5.0.0
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### Workflow

Configure the version of **Node.js** used for development of the project in the `env.NODE_VERSION` field of `check-action-metadata-task.yml`.

#### `.gitignore`

Add the following to [`/.gitignore`](https://git-scm.com/docs/gitignore):

```
/node_modules/
```

### Readme badge

Markdown badge:

```markdown
[![Check Action Metadata status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-action-metadata-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-action-metadata-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-action-metadata-task.yml/badge.svg["Check Action Metadata status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-action-metadata-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```text
Add CI workflow to validate action.yml

A task and GitHub Actions workflow are provided here for validating the action.yml metadata file of GitHub Actions
actions.

On every push or pull request that affects the metadata file, and periodically, validate action.yml against its JSON
schema.
```

## PR message

```markdown
A task and GitHub Actions workflow are provided here for validating the [`action.yml`](https://docs.github.com/actions/creating-actions/metadata-syntax-for-github-actions) metadata file of [GitHub Actions actions](https://docs.github.com/actions/learn-github-actions/understanding-github-actions#actions).

On every push or pull request that affects the metadata file, and periodically, validate `action.yml` against [its JSON schema](https://json.schemastore.org/github-action.json).
```
