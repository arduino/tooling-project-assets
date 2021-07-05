// Source: https://github.com/arduino/tooling-project-assets/blob/main/workflow-templates/assets/deploy-cobra-mkdocs-versioned-poetry/docsgen/go.mod
// TODO: replace MODULE_NAME with the project's module name
module MODULE_NAME/docsgen

go 1.14

replace MODULE_NAME => ../

require (
	MODULE_NAME v0.0.0
	github.com/spf13/cobra v1.1.1
)
