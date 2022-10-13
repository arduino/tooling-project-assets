# "Deploy Website" workflow (versioned, MkDocs, Poetry)

Deploy a versioned [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).

Documentation content will sometimes apply only to a specific version of the project. For this reason, it's important for the reader to be able to access the documentation for the specific version of the project they are using.
The system provides a easy access to a website version for the documentation content at:

- The tip of the default branch ("dev")
- The latest release ("latest")
- Each minor version series (e.g., "1.2")

The website version is selectable via a menu on the website as well as the URL of each documentation page.

## Installation

### Workflow

Install the [`deploy-mkdocs-versioned-poetry.yml`](deploy-mkdocs-versioned-poetry.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- Base assets - See the ["Deploy Website" workflow (MkDocs, Poetry) documentation](deploy-mkdocs-poetry.md#assets)
- [`siteversion.py`](assets/deploy-mkdocs-versioned/siteversion/siteversion.py) - versioning helper script.
  - Install to: `docs/siteversion/`

### Dependencies

### Define base dependencies

See the ["Deploy Website" workflow (MkDocs, Poetry) documentation](deploy-mkdocs-poetry.md#dependencies) for the instructions to install the base dependencies

### Define additional dependencies

1. Run this command:
   ```
   poetry add --dev "gitpython@^3.1.29" "mike@^1.1.2"
   ```
1. Commit the resulting `pyproject.toml` and `poetry.lock` files.

### Configuration

#### Configure base assets

See the ["Deploy Website" workflow (MkDocs, Poetry) documentation](deploy-mkdocs-poetry.md#configuration)

#### Define "dev" source branch

The system is configured for the repository branch used as the source for the "dev" website version having the name `main`. If the project's development branch has another name, then configure it:

- `on.push.branches[0]` in `deploy-mkdocs-versioned-poetry.yml`
- `DEV_BRANCHES` in [`docs/siteversion/siteversion.py`](assets/deploy-mkdocs-versioned/siteversion/siteversion.py)

#### Configure Material theme for versioning

Add the following to `mkdocs.yml`:

```yaml
extra:
  version:
    provider: mike
```

(information [here](https://squidfunk.github.io/mkdocs-material/setup/setting-up-versioning/))

#### Configure `.gitignore`

Add the following to `.gitignore`:

```
/site/
```

### Setup

1. Checkout the branch of the repository that contains the documentation source files for the "dev" version of the website (e.g., `main`).
1. Run the following command:
   ```
   poetry run mike delete --all && \
     poetry run mike deploy dev && \
     poetry run mike set-default --push dev
   ```

This will do the following:

- If the repository already has a `gh-pages` branch, remove the content, otherwise create the branch.
- Generate the "dev" version of the website.
- Configure the website root url (e.g., https://arduino.github.io/arduino-cli) to redirect to the "dev" version of the website (e.g., https://arduino.github.io/arduino-cli/dev/).
- Publish the website via GitHub Pages.

After this initial deployment, all further website updates will be handled automatically by the "Deploy Website" workflow.

### Documentation

#### Readme badge

Markdown badge:

```markdown
[![Deploy Website status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/deploy-mkdocs-versioned-poetry.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/deploy-mkdocs-versioned-poetry.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-mkdocs-versioned-poetry.yml/badge.svg["Deploy Website status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-mkdocs-versioned-poetry.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

#### Development Guide

See the ["Deploy Website" workflow (MkDocs, Poetry) documentation](deploy-mkdocs-poetry.md#development-guide)

## Website versioning

This system is designed for projects that use release branches. The website versioning is based on branch names:

- "dev" - This version of the website is updated on every push to the repository's development branch (e.g., `main`).
- release versions - These are automatically generated on the creation of a branch named with the format `X.Y.x` (e.g., `1.2.x`), where `X` is the major version number, `Y` is the minor version number, and `x` is a placeholder for the patch versions of that minor version series, which share a single release branch. A website version name `X.Y` is created for this branch and updated from that branch's contents on every push.
- "latest" - redirects to the newest release version.

The website root URL was configured to redirect to the "dev" version of the website during the [setup](#setup). Once the first release version of the website has been generated by the creation of a release branch, this should be changed to redirect to the "latest" version by running this command:

```
poetry run mike set-default --push latest
```

## Commit message

```
Add CI workflow to deploy a versioned MkDocs-based website to GitHub Pages

On every push to the repository's default branch or release branch, deploy the repository's MkDocs-based static website
to GitHub Pages.

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
On every push to the repository's default branch, deploy the repository's [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).

Documentation content will sometimes apply only to a specific version of the project. For this reason, it's important
for the reader to be able to access the documentation for the specific version of the project they are using.

With the help of [mike](https://github.com/jimporter/mike), the documentation system provides access to:

- The tip of the default branch ("dev")
- The latest release ("latest")
- Each minor version series (e.g., "1.2")

The website version is selectable via a menu on the website as well as the URL of each documentation page.
```
