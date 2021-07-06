# "Deploy Website" workflow (Cobra, versioned, MkDocs, Poetry)

Generate a command line reference for projects using [the Cobra Go module](https://cobra.dev/) and deploy a versioned [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).

This uses Cobra's built-in Markdown documentation generation capability:<br/>
https://github.com/spf13/cobra/blob/master/doc/md_docs.md

Documentation content will sometimes apply only to a specific version of the project. For this reason, it's important for the reader to be able to access the documentation for the specific version of the project they are using.
The system provides a easy access to a website version for the documentation content at:

- The tip of the default branch ("dev")
- The latest release ("latest")
- Each minor version series (e.g., "1.2")

The website version is selectable via a menu on the website as well as the URL of each documentation page.

## Installation

### Workflow

Install the [`deploy-cobra-mkdocs-versioned-poetry.yml`](deploy-cobra-mkdocs-versioned-poetry.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- Base assets - See the ["Deploy Website" workflow (versioned, MkDocs, Poetry) documentation](deploy-mkdocs-versioned-poetry.md#assets)
- [`Taskfile.yml`](assets/deploy-cobra-mkdocs-versioned-poetry/Taskfile.yml) - documentation generation tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/check-prettier-formatting/Taskfile.yml) - documentation formatting task.
  - Merge into `Taskfile.yml`
- [`docsgen`](assets/cobra/docsgen) - command line reference generator.
  - Install to: `docsgen/`

### Dependencies

See the ["Deploy Website" workflow (versioned, MkDocs, Poetry) documentation](deploy-mkdocs-versioned-poetry.md#dependencies) for the instructions to install the dependencies

### Configuration

#### Taskfile

Set the `PROJECT_NAME` variable to the project name.

If there are any additional documentation generation tasks, add them to the `docs:generate` umbrella task.

#### `docsgen`

- [`go.mod`](assets/cobra/docsgen/go.mod) - replace `MODULE_NAME` with the project's module name.
- [`main.go`](assets/cobra/docsgen/main.go) - replace `CLI_PACKAGE_NAME` with the project's Cobra CLI package name

Run the following command from the `docsgen/` folder:

```
go mod tidy
```

Commit the resulting `docsgen/go.sum` file to the repository.

#### Configure base assets

See the ["Deploy Website" workflow (versioned, MkDocs, Poetry) documentation](deploy-mkdocs-versioned-poetry.md#configuration).

#### Define "dev" source branch

The system is configured for the repository branch used as the source for the "dev" website version having the name `main`. If the project's development branch has another name, then configure it:

- `on.push.branches[0]` in `deploy-cobra-mkdocs-versioned-poetry.yml`
- `DEV_BRANCHES` in [`siteversion/siteversion.py`](assets/deploy-mkdocs-versioned/siteversion/siteversion.py)

#### Configure `.gitignore`

Add the following to `.gitignore`:

```
/docsgen/<application executable>
/docsgen/<application executable>.exe
/docs/commands/*.md
```

(where "`<application executable>`" is the filename of the application's executable, as defined in the Taskfile `PROJECT_NAME` variable.

### Setup

1. Checkout the branch of the repository that contains the documentation source files for the "dev" version of the website (e.g., `main`).
1. Run the following command:
   ```
   task docs:generate
   ```
1. Follow the remaining setup steps from the ["Deploy Website" workflow (versioned, MkDocs, Poetry) documentation](deploy-mkdocs-versioned-poetry.md#setup).

### Readme badge

Markdown badge:

```markdown
[![Deploy Website status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/deploy-cobra-mkdocs-versioned-poetry.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/deploy-cobra-mkdocs-versioned-poetry.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-cobra-mkdocs-versioned-poetry.yml/badge.svg["Deploy Website status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-cobra-mkdocs-versioned-poetry.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Website versioning

See the ["Deploy Website" workflow (versioned, MkDocs, Poetry) documentation](deploy-mkdocs-versioned-poetry.md#website-versioning) for an explanation of how the versioning works.

## Commit message

```
Add CI workflow to deploy a versioned MkDocs-based website to GitHub Pages

On every push to the repository's default branch or release branch, generate a command line reference and deploy the
repository's MkDocs-based static website to GitHub Pages.

Documentation content will sometimes apply only to a specific version of the project. For this reason, it's important
for the reader to be able to access the documentation for the specific version of the project they are using.

The documentation system provides access to:

- The tip of the default branch ("dev")
- The latest release ("latest")
- Each minor version series (e.g., "1.2")

The website version is selectable via a menu on the website as well as the URL of each documentation page.
```

## PR message

```markdown
On every push to the repository's default branch, generate a command line reference and deploy the repository's [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).

Documentation content will sometimes apply only to a specific version of the project. For this reason, it's important
for the reader to be able to access the documentation for the specific version of the project they are using.

With the help of [mike](https://github.com/jimporter/mike), the documentation system provides access to:

- The tip of the default branch ("dev")
- The latest release ("latest")
- Each minor version series (e.g., "1.2")

The website version is selectable via a menu on the website as well as the URL of each documentation page.
```
