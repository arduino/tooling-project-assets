# "Check ToC" workflow (Task)

Check whether the generated table of contents in Markdown files matches their heading structure.

This should be used in repositories that generate the table of contents with [markdown-toc](https://github.com/jonschlinkert/markdown-toc).

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-toc-task.yml`](check-toc-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.npmrc`](assets/npm/.npmrc) - **npm** configuration file.
  - Install to: repository root.
- [`Taskfile.yml`](assets/check-toc-task/Taskfile.yml) - Table of contents generation task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Dependencies

The tool dependencies of this workflow are managed by [npm](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev markdown-toc@^1.2.0
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### Node.js

Configure the version of [**Node.js**](https://nodejs.org) used for development of the project by running the following command from a terminal in the project repository folder:

```text
npm pkg set engines.node=22.x
```

#### Workflow

The workflow is configured to check a table of contents in `README.md`. If other files have a table of contents, adjust the following fields in `check-toc-task.yml`:

- `on.push.paths`
- `on.pull_request.paths`
- `jobs.check.strategy.matrix.file[]`

#### `.gitignore`

Add the following to [`/.gitignore`](https://git-scm.com/docs/gitignore):

```
/node_modules/
```

### Readme badge

Markdown badge:

```markdown
[![Check ToC status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-toc-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-toc-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-toc-task.yml/badge.svg["Check ToC status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-toc-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to generate a ToC

A task is provided to use the "markdown-toc" tool to generate a table of contents for Markdown files in the project.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
A task is provided to use the [**markdown-toc**](https://github.com/jonschlinkert/markdown-toc) tool to generate a table of contents for Markdown files in the project.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```
