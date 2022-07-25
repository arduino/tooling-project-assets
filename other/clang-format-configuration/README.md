# ClangFormat configuration file for official Arduino code style

This is a configuration file for [the **ClangFormat** code formatting tool](https://clang.llvm.org/docs/ClangFormat.html).

The code style defined in this file is the standardized [Arduino language](https://www.arduino.cc/reference/en/)/C++/C style to be used in all official Arduino projects.

## Validation

The configuration is designed to produce the Arduino code style as established by the Arduino IDE's "**Auto Format**" feature and the code of the sketches and libraries written by Arduino.

It is used by multiple official Arduino projects as well as by the community. Any changes to the formatter output can be disruptive and so should only be made deliberately after proper evaluation and review of the impact.

**ClangFormat** is a very complex tool which is under active development. This means that unintended changes to the formatter output might result from:

- Side effects of intentional configuration changes.
- Differences in **ClangFormat**'s handling of existing configuration options after updating to a new version.
- Introduction of new configuration options after updating to a new version.

For this reason, it is necessary to carefully validate the configuration in preparation for:

- Changes to the configuration file
- Updating the version of **ClangFormat** used in Arduino's projects

Validation is done by formatting a collection of test data files and then comparing the result against "golden masters" which have the intended formatting. The repository's continuous integration system does this check after every change to relevant files. It can also be run locally using [the **Task** task runner tool](https://taskfile.dev/):

```text
task clang-format:check-configuration
```

### ClangFormat version updates

The validation is done using Arduino's current standard version of **ClangFormat** by default. When an update to a different version of **ClangFormat** is planned, configuration validation must be done against the candidate version.

#### Running the check locally

1. Install the candidate **ClangFormat** version on your machine.
   **ⓘ** In addition to the standard sources, Arduino provides builds [here](https://github.com/arduino/clang-static-binaries/releases)
1. Add the location of the **ClangFormat** installation to your `PATH`.
1. Run the Task command, specifying the version via an argument:
   ```text
   task clang-format:check-configuration CLANG_FORMAT_VERSION=<version>
   ```
   **ⓘ**Replace `<version>` in the command with the version of the **ClangFormat** candidate.

#### Running the check via GitHub Actions

The GitHub Actions workflow can be triggered manually, with the option to specify an arbitrary version of **ClangFormat** to run the validation against.

1. Check whether a build of the candidate version is available [here](https://github.com/arduino/clang-static-binaries/releases).
   If not, submit an issue in that repository requesting a build.
1. Open https://github.com/arduino/tooling-project-assets/actions/workflows/check-clang-format.yml
1. Click the <kbd>**Run Workflow**</kbd> button.
1. Enter the **ClangFormat** candidate version in the "**ClangFormat version**" input field.
1. Click the <kbd>**Run Workflow**</kbd> button.
1. Wait for the workflow run to finish.
1. Check the results.

#### Updating the default ClangFormat version

Once a new version of **ClangFormat** has been adopted as the standard for use in Arduino projects, it must be set as the default for use in the validations. This default version is defined by the `vars.DEFAULT_CLANG_FORMAT_VERSION` field of [`Taskfile.yml`](../../Taskfile.yml).

### Updating the "golden masters"

The goal is for the configuration to produce output compliant with the established official Arduino code style. For this reason, differences in output resulting from a configuration change or **ClangFormat** update should not be taken lightly.

When changes are unavoidable, the test data "golden masters" must be updated accordingly:

#### Via local operation

Run the following command

```text
task clang-format:update-golden
```

#### Via GitHub Actions

As an alternative to running the update command locally, you can download the files from a workflow artifact named "**testdata-output**" which is available in the "**Summary**" page of each workflow run where the `check-output` job of the "**Check ClangFormat Configuration**" workflow failed due to the current golden masters not matching the output.

Save the contents of the downloaded ZIP file to [the `testdata/golden/` folder](testdata/golden/).
