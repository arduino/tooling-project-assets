# "Release" workflow (Go, Task, CGO)

Make a production release of the [Go](https://golang.org/) with [CGO](https://go.dev/blog/cgo) enabled, using [elastic docker containers](https://github.com/elastic/golang-crossbuild).

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`release-go-task.yml`](release-go-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/release-go-task/Taskfile.yml) - [variables](https://taskfile.dev/#/usage?id=variables) providing project-specific data to the build system.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`DistTasks.yml`](assets/release-go-task/DistTasks.yml) - general purpose tasks for making production builds of Go projects using cgo and [elastic docker containers](https://github.com/elastic/golang-crossbuild).
  - Install to: repository root
- [Installation script and documentation](../other/installation-script/README.md)

### Configuration

#### Taskfile

The following project-specific variables must be set in `Taskfile.yml`:

- `PROJECT_NAME`
- `CONFIGURATION_PACKAGE`

`CONFIGURATION_PACKAGE` must be set to the golang package containing the version metadata for the project. For example for the following file: https://github.com/arduino/mdns-discovery/blob/main/version/version.go the `CONFIGURATION_PACKAGE` field must be set to the value: `github.com/arduino/mdns-discovery/version`.

#### Workflow

The following project-specific variables must be set in `release-go-task.yml`:

- `PROJECT_NAME`
- `AWS_PLUGIN_TARGET`

#### AWS IAM Role

We need a special [IAM Role](https://docs.aws.amazon.com/rolesanywhere/latest/userguide/introduction.html#access) to upload files on the S3 bucket. This IAM Role is able to generate short lived credentials with push access to specific S3 subpaths. To generate a new role for a new repository kindly ask DevOps (providing the repository link and path you need files on S3).

#### Repository secrets

The following [repository secrets](https://docs.github.com/actions/how-tos/write-workflows/choose-what-workflows-do/use-secrets#creating-encrypted-secrets-for-a-repository) must be defined:

- `INSTALLER_CERT_MAC_P12` - the [Apple Developer ID](https://developer.apple.com/support/developer-id/) signing certificate, exported in [PKCS #12 format](https://wikipedia.org/wiki/PKCS_12) and then encoded into base64 as described [here](https://www.kencochrane.com/2020/08/01/build-and-sign-golang-binaries-for-macos-with-github-actions/#exporting-the-developer-certificate).
- `INSTALLER_CERT_MAC_PASSWORD` - the password used to encrypt the Apple Developer ID signing certificate during the export process.
- `AC_USERNAME` - the Apple ID username associated with the certificate.
- `AC_PROVIDER` - the App Store Connect provider via. You can use the ID of the certificate identity (e.g., `7KT7ZWMCJT`) for this.
- `AC_PASSWORD` - [App-specific password](https://support.apple.com/en-us/HT204397) created for the Apple ID.
- `DOWNLOADS_BUCKET` - [AWS bucket](https://docs.aws.amazon.com/AmazonS3/latest/userguide/UsingBucket.html) on the downloads server.

The following [environment secrets](https://docs.github.com/actions/how-tos/deploy/configure-and-manage-deployments/manage-environments#environment-secrets) must be defined under `production` environment:

- `AWS_ROLE_TO_ASSUME` - [AWS role](https://docs.aws.amazon.com/IAM/latest/UserGuide/id_roles.html) to generate temporary security credentials.

### Readme badge

Markdown badge:

```markdown
[![Release status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/release-go-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/release-go-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/release-go-task.yml/badge.svg["Release status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/release-go-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to publish releases

On every push of a tag named with a version format:

- Build the project for all supported platforms.
- Sign and notarize the macOS builds.
- Create a GitHub release.
  - Builds and checksums are attached as release assets
  - A changelog generated from the commit history is added to the release description
  - If the tag has a pre-release version suffix, the GitHub release will be marked as a pre-release.
- Upload the builds to Arduino's downloads server.
```

## PR message

```markdown
On every push of a tag named with a version format:

- Build the project for all supported platforms.
- Use [gon](https://github.com/Bearer/gon) to sign and notarize the macOS builds.
- Create a [GitHub release](https://docs.github.com/repositories/releasing-projects-on-github/about-releases).
  - Builds and checksums are attached as release assets
  - A changelog generated by [`arduino/create-changelog`](https://github.com/arduino/create-changelog) from the commit history is added to the release description
  - If the tag has [a pre-release version suffix](https://semver.org/), the GitHub release will be marked as a pre-release.
- Upload the builds to Arduino's downloads server.
```
