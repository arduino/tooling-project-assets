# "Check JavaScript" workflow (Task)

Workflow file: [check-javascript-task.yml](check-javascript-task.yml)

Use [**ESLint**](https://eslint.org/) to lint the repository's JavaScript files.

**Note:** This workflow is focused on linting. Formatting checks for JavaScript are provided by the ["Check Prettier Formatting" workflow (Task)](https://github.com/arduino/tooling-project-assets/blob/main/workflow-templates/check-prettier-formatting-task.md), so both should be used.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-javascript-task.yml`](check-javascript-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.eslintrc.yml`](assets/check-javascript/.eslintrc.yml) - **ESLint** configuration file.
  ❗ The code style defined in this file is the official standardized style to be used in all Arduino projects and should not be modified.
  - Install to: repository root
- [`.npmrc`](assets/npm/.npmrc) - **npm** configuration file.
  - Install to: repository root.
- [`Taskfile.yml`](assets/check-javascript-task/Taskfile.yml) - JavaScript linting tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Dependencies

The tool dependencies of this workflow are managed by [npm](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev eslint@^8.57.0 eslint-config-prettier@^10.1.3
npx install-peerdeps --dev eslint-config-airbnb-base
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### `.gitignore`

Add the following to [`/.gitignore`](https://git-scm.com/docs/gitignore):

```gitignore
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
[![Check JavaScript status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-javascript-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-javascript-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-javascript-task.yml/badge.svg["Check JavaScript status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-javascript-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to lint JavaScript code

A task is provided to run ESLint on the project's JavaScript files.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
A task is provided to run [**ESLint**](https://eslint.org/) on the project's JavaScript files.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```
