# Documentation Templates

## Contributor Guide

The file `CONTRIBUTING.md` serves as an entry point to the content. This file is given special treatment by GitHub, which presents it to potential contributors:

https://docs.github.com/communities/setting-up-your-project-for-healthy-contributions/setting-guidelines-for-repository-contributors

### Installation

Install the files and folders from [`contributor-guide/general/`](contributor-guide/general/) to the `docs/` subfolder of the repository.

#### Beta Testing Guide

An additional file named `beta-testing.md` must be added to the `docs/contributor-guide/` subfolder of the repository.

##### Application Projects

If tester builds are generated for the project, use the template files from [`contributor-guide/application/contributor-guide/beta-testing.md`](contributor-guide/application/contributor-guide/beta-testing.md).

The project is assumed to use a workflow with the standardized name "**Publish Tester Build**" to produce tester builds for pull requests.

A workflow template for Go-based projects is available [here](../workflow-templates/publish-go-tester-task.md).

##### Other Projects

A basic template providing the standardized structure for the document is available at [`contributor-guide/other/contributor-guide/beta-testing.md`](contributor-guide/other/contributor-guide/beta-testing.md).

#### Development Guide

An additional file named `development.md` must be added to the `docs/` subfolder of the repository.

##### Task-Based Projects

For projects which use the standardized Task-based approach to project management, use the template file from [`contributor-guide/task/development.md`](contributor-guide/task/development.md).

The taskfile must contain the following standardized "umbrella" tasks:

- `build` - build the project
- `check` - run all tasks that check for problems with the project
- `fix` - run all tasks that make automated corrections to the project's files

##### Other Projects

A basic template providing the standardized structure for the document is available at [`contributor-guide/other/development.md`](contributor-guide/other/development.md).

#### Configuration

"**TODO**" comments and placeholders mark the locations in the documents where project-specific adjustments or additions should be made.

### Commit message

```text
Add a project contributor guide

Documentation of how to contribute to the project gives everyone the opportunity to participate, while also reducing
maintenance effort and increasing quality of contributions.

This guide documents the various ways of contributing to the project.

It takes advantage of GitHub's "contributing guidelines" feature to increase the visibility of the information to
prospective contributors. The promoted "CONTRIBUTING.md" file is used as an entry point to the guide, with links from
there leading to dedicated guides for each specific type of contribution. In this way, the contributor is only presented
with relevant information, improving the approachability and readability of the content.
```

### PR message

```markdown
Documentation of how to contribute to the project gives everyone the opportunity to participate, while also reducing maintenance effort and increasing quality of contributions.

This guide documents the various ways of contributing to the project.

It takes advantage of [GitHub's "contributing guidelines" feature](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/setting-guidelines-for-repository-contributors) to increase the visibility of the information to prospective contributors. The promoted `CONTRIBUTING.md` file is used as an entry point to the guide, with links from there leading to dedicated guides for each specific type of contribution. In this way, the contributor is only presented with relevant information, improving the approachability and readability of the content.
```
