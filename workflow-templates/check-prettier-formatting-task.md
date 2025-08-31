# "Check Prettier Formatting" workflow (Task)

Use [Prettier](https://prettier.io/docs/en/index.html) to check formatting. Supported languages include:

- JavaScript
- TypeScript
- CSS
- HTML
- JSON
- Markdown
- TOML ([via plugin](#toml-support-optional))
- YAML

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-prettier-formatting-task.yml`](check-prettier-formatting-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.npmrc`](assets/npm/.npmrc) - **npm** configuration file.
  - Install to: repository root.
- [`Taskfile.yml`](assets/check-prettier-formatting-task/Taskfile.yml) - Formatting task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`.prettierignore`](assets/check-prettier-formatting/.prettierignore) - ignore paths configuration file.
  - Install to: repository root.

### Dependencies

The tool dependencies of this workflow are managed by [npm](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev prettier@^3.5.3
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### Node.js

Configure the version of [**Node.js**](https://nodejs.org) used for development of the project by running the following command from a terminal in the project repository folder:

```text
npm pkg set engines.node=22.x
```

#### Prettier

Prettier should be configured via a `.prettierignore` file to ignore any externally maintained files contained in the repository:
https://prettier.io/docs/en/ignore.html

Support for additional languages can be added to Prettier via plugins:
https://prettier.io/docs/en/plugins.html

Prettier automatically determines the language based on file name. In cases where it is not able to recognize a file, the parser can be specified in a `.prettierrc.yml` configuration file:
https://prettier.io/docs/en/configuration.html#setting-the-parserdocsenoptionshtmlparser-option

The default Prettier code style is the official standardized style to be used in all Arduino tooling projects and should not be modified.

#### `.gitignore`

Add the following to [`/.gitignore`](https://git-scm.com/docs/gitignore):

```
/node_modules/
```

### TOML Support (Optional)

If the project contains manually maintained [TOML](https://toml.io/) language files, some additional configuration is needed to add support to Prettier for this language.

#### Assets

- [`.prettierrc.yml`](assets/check-prettier-formatting/toml/.prettierrc.yml) - Prettier configuration file
  - Install to: repository root.

#### Dependencies

Add the TOML support dependencies by running this command:

```text
npm install --save-dev prettier-plugin-toml@^2.0.2
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Readme badge

Markdown badge:

```markdown
[![Check Prettier Formatting status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-prettier-formatting-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-prettier-formatting-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-prettier-formatting-task.yml/badge.svg["Check Prettier Formatting status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-prettier-formatting-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure for code formatting via Prettier

A task is provided to format project files using the Prettier code formatting tool.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
A task is provided to format project files using the [**Prettier**](https://prettier.io/docs/en/index.html) code formatting tool.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```
