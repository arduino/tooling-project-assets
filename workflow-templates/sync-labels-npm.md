# "Sync Labels" workflow (npm)

Use [github-label-sync](https://github.com/Financial-Times/github-label-sync) to configure the repository's [issue/pull request labels](https://docs.github.com/issues/using-labels-and-milestones-to-track-work/managing-labels) according to the universal, shared, and local label configuration files.

Use of consistent labels across repositories makes repository maintenance and searching of issue and pull request trackers easier.

Some label definitions in the configuration file contain a `notes` field. This provides additional information about the proper usage of the label when this might not be clear from the label name and description. The `notes` field is purely for documentation purposes and has no effect on the repository labels.

This is the version of the workflow using [npm](https://www.npmjs.com/) for dependencies management.

## Installation

### Workflow

Install the [`sync-labels-npm.yml`](sync-labels-npm.yml) GitHub Actions workflow to `.github/workflows/`

### Dependencies

The tool dependencies of this workflow are managed by [npm](https://www.npmjs.com/).

Add the dependencies by running this command:

```text
npm install --save-dev ajv-cli@^5.0.0 ajv-formats@^3.0.1
npm install --save-dev --save-exact github-label-sync@3.0.0
```

Commit the resulting changes to the `package.json` and `package-lock.json` files.

### Configuration

#### Labels

Multiple labels data files can be merged to form the list of labels for the repository. The [universal labels](assets/sync-labels/universal.yml) must be used in all repositories, but some projects will benefit from the addition of other domain-specific labels.

The configuration file structure is documented here: https://github.com/Financial-Times/github-label-sync#label-config-file

##### Maximum string lengths

Label sync will fail with a `422: Validation Failed` error if a label configuration string exceeds the maximum length.

- `name`: 50
- `description`: 100
  - Note: `description` is truncated at ~45 (depending on width) characters in the labeling menu, so make sure the meaning of the label is clear to the maintainer from the visible subset of the description.

##### Standardized label colors

These colors have good contrast. When possible, follow the conventions established in the universal labels for the general meaning associated the colors.

- `#940404`
- `#ff0000`
- `#ffa200`
- `#ffff00`
- `#00ff00`
- `#92a600`
- `#008000`
- `#00ba9e`
- `#00ffff`
- `#0000ff`
- `#800080`
- `#d876e3`
- `#ff00ff`
- `#c0c0c0`

###### Notes

- Remove the `#` from the hex color code before adding it to the `color` field of the labels definition file.
- Black and white should not be used due to lacking contrast with the GitHub page background colors (light and dark themes).

##### Shared labels

Configuration files for labels that are applicable to multiple projects are hosted [here](assets/sync-labels).

Add the file name to the `jobs.download.strategy.matrix.filename[]` array in the workflow.

##### Project-specific labels

The configuration file for labels that only apply to the specific project should be located in `.github/label-configuration-files/`

#### `.gitignore`

Add the following to `.gitignore`:

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
[![Sync Labels status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/sync-labels-npm.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/sync-labels-npm.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/sync-labels-npm.yml/badge.svg["Sync Labels status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/sync-labels-npm.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to synchronize with shared repository labels

On every push that changes relevant files, and periodically, configure the repository's issue and pull request labels
according to the universal, shared, and local label configuration files.
```

## PR message

```markdown
On every push that changes relevant files, and periodically, use [github-label-sync](https://github.com/Financial-Times/github-label-sync) to configure the repository's issue/PR labels according to the universal, shared, and local label configuration files.
```
