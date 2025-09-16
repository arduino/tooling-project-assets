# "Check Markdown" workflow (Task)

Check the repository's Markdown files for problems:

- Use [markdownlint-cli](https://github.com/igorshubovych/markdownlint-cli) to check for common problems and formatting.
- Use [markdown-link-check](https://github.com/tcort/markdown-link-check) to check for broken links.

NOTE: This workflow is focused on linting. Formatting checks for Markdown are provided by the ["Check Prettier Formatting" workflow](check-prettier-formatting-task.md), so both should be used.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-markdown-task.yml`](check-markdown-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.markdown-link-check.json`](assets/check-markdown/.markdown-link-check.json) - markdown-link-check configuration file.
  - Install to: repository root
- [`.markdownlint.yml`](assets/check-markdown/.markdownlint.yml) - markdownlint configuration file.
  - Install to: repository root
- [`.markdownlintignore`](assets/check-markdown/.markdownlintignore) - markdownlint configuration file.
  - Install to: repository root
- [`.npmrc`](assets/npm/.npmrc) - **npm** configuration file.
  - Install to: repository root.
- [`Taskfile.yml`](assets/check-markdown-task/Taskfile.yml) - Markdown tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

The code style defined in `.markdownlint.yml` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Dependencies

The tool dependencies of this workflow are managed by [npm](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev markdown-link-check@^3.13.7 markdownlint-cli@^0.45.0
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### Node.js

Configure the version of [**Node.js**](https://nodejs.org) used for development of the project by running the following command from a terminal in the project repository folder:

```text
npm pkg set engines.node=22.x
```

#### Taskfile

Add any documentation generation processes to the `docs:generate` umbrella task.

#### markdownlint

In the event the repository contains externally maintained Markdown files, `markdownlint` can be configured to ignore them via a `.markdownlintignore` file:
https://github.com/igorshubovych/markdownlint-cli#ignoring-files

#### markdown-link-check

Advanced configuration of `markdown-link-check` can be done via the [`.markdown-link-check.json`](assets/check-markdown/.markdown-link-check.json) configuration file:
https://github.com/tcort/markdown-link-check#config-file-format

#### `.gitignore`

Add the following to [`/.gitignore`](https://git-scm.com/docs/gitignore):

```
/node_modules/
```

### Readme badge

Markdown badge:

```markdown
[![Check Markdown status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-markdown-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-markdown-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-markdown-task.yml/badge.svg["Check Markdown status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-markdown-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to check for problems in Markdown files

Tasks are provided to check for problems in the project's Markdown files:

- Use markdownlint to check for common problems and formatting.
- Use markdown-link-check to check for broken links.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
Add infrastructure to check for problems in Markdown files

Tasks are provided to check for problems in the project's Markdown files:

- Use [markdownlint-cli](https://github.com/igorshubovych/markdownlint-cli) to check for common problems and formatting.
- Use [markdown-link-check](https://github.com/tcort/markdown-link-check) to check for broken links.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```
