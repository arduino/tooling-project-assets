# "Check Prettier Formatting" workflow (Task)

Use [Prettier](https://prettier.io/docs/en/index.html) to check formatting. Supported languages include:

- JavaScript
- TypeScript
- CSS
- HTML
- JSON
- Markdown
- YAML

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-prettier-formatting-task.yml`](check-prettier-formatting-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

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
npm install --save-dev prettier@^3.5.2
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### Workflow

Configure the version of Node.js used for development of the project in the `env.NODE_VERSION` field of `check-prettier-formatting-task.yml`.

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
Add CI workflow to check for Prettier formatting compliance

On every push and pull request that affects relevant files, check whether the formatting of supported
files is compliant with the Prettier style.
```

## PR message

```markdown
On every push and pull request that affects relevant files, check whether the formatting of supported files is compliant with the [Prettier](https://prettier.io/docs/en/index.html) style.
```
