# Installation script

This shell script does the following:

1. If no version was specified via the command line, scrape the HTML of the project repository's releases page to determine the latest version.
1. Download appropriate version and architecture of the application from Arduino's download server.
1. Extract the downloaded archive to the appropriate location.
1. Notify the user if the installation is not in their `$PATH`.

## Requirements

- Executable has a `--version` flag.
- Release archives follow the standard file name format, as provided by the [release](../../workflow-templates/release-go-task.md) and (nightly)[../../workflow-templates/publish-go-nightly-task.md) template workflows.
- Release archives are downloadable from `downloads.arduino.cc`

## Installation

### Assets

- [`install.sh`](install.sh) - installation script
  - Install to: `etc/`
- [`installation.md`](installation.md) - installation instructions
  - Install to: `docs/`

### Configuration

Set the `PROJECT_NAME` variable in `install.sh` to the project's repository name (e.g., "arduino-cli").

Replace all occurrences of `TODO_PRODUCT_NAME` in `installation.md` with the project's product name (e.g., "Arduino CLI").

Replace all occurrences of `TODO_REPO_NAME` in `installation.md` with the project's repository name (e.g., "arduino-cli").

## Commit message

```
Add installation script

This shell script provides the option to install the application with a single command.

It defaults to installing the latest release to `./bin/`, but the user also has the option of specifying a version and installation path.
```
