# "Check ToC" workflow (Task)

Check whether the generated table of contents in Markdown files matches their heading structure.

This should be used in repositories that generate the table of contents with [markdown-toc](https://github.com/jonschlinkert/markdown-toc).

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-toc-task.yml`](check-toc-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

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

#### Workflow

The workflow is configured to check a table of contents in `README.md`. If other files have a table of contents, adjust the following fields in `check-toc-task.yml`:

- `on.push.paths`
- `on.pull_request.paths`
- `jobs.check.strategy.matrix.file[]`

Configure the version of Node.js used for development of the project in the `env.NODE_VERSION` field of `check-toc-task.yml`.

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
Add CI workflow to check for missed updates to generated ToC

On every push or pull request that affects the repository's Markdown files that contain a generated table of contents,
check whether the table of contents matches the file structure.
```

## PR message

```markdown
On every push or pull request that affects the repository's Markdown files that contain a generated table of contents, use [markdown-toc](https://github.com/jonschlinkert/markdown-toc) to check whether the table of contents matches the file structure.
```
