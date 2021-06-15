# "Check License" workflow

Workflow file: [check-license.yml](check-license.yml)

Check whether the repository's license file is recognizable by GitHub's [automated license detection system](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/licensing-a-repository#detecting-a-license) and whether it is recognized as the correct type. In order to be detected (and to ensure it remains a valid legal instrument), the license text must not be modified. GitHub supports multiple license filenames, so it's also possible that the license type could be inadvertently changed by the addition of a file to the repository.

Please always use the exact license text from the links at https://choosealicense.com/appendix/

## Readme badge

Markdown badge:

```markdown
[![Check License status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-license.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-license.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-license.yml/badge.svg["Check License status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-license.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check the license file

Whenever one of the recognized license file names are modified in the repository, the workflow runs to check whether the
license can be recognized and whether it is of the expected type.

GitHub has a useful automated license detection system that determines the license type used by a repository, and
surfaces that information in the repository home page, the search web interface, and the GitHub API. This license
detection system requires that the license be defined by a dedicated file with one of several standardized filenames and
paths.

GitHub's license detection system uses the popular licensee tool, so this file also serves to define the license type
for any other usages of licensee, as well as to human readers of the file.

For this reason, and to ensure it remains a valid legal instrument, it's important that there be no non-standard
modifications to the license file or collisions with other supported licence files. This workflow ensures that any
changes which would change the license type or which license file is used by the detection are caught automatically.
```

## PR message

```markdown
Whenever one of the recognized license file names are modified in the repository, the workflow runs [licensee](https://github.com/licensee/licensee) to check whether the license can be recognized and whether it is of the expected type.

GitHub has a useful [automated license detection system](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/licensing-a-repository#detecting-a-license) that determines the license type used by a repository, and surfaces that information in the repository home page, the search web interface, and the GitHub API. This license detection system requires that the license be defined by a dedicated file with one of several standardized filenames and paths.

GitHub's license detection system uses the popular licensee tool, so this file also serves to define the license type for any other usages of licensee, as well as to human readers of the file.

For this reason, and to ensure it remains a valid legal instrument, it's important that there be no non-standard modifications to the license file or collisions with other supported licence files. This workflow ensures that any changes which would change the license type or which license file is used by the detection are caught automatically.
```
