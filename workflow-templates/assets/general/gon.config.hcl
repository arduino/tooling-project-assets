# Source: https://github.com/arduino/tooling-project-assets/blob/main/workflow-templates/assets/general/gon.config.hcl
# See: https://github.com/mitchellh/gon#configuration-file
source = [TODO_SOURCE_PATH]
bundle_id = TODO_BUNDLE_ID

sign {
  application_identity = "Developer ID Application: ARDUINO SA (7KT7ZWMCJT)"
}

# Ask Gon for zip output to force notarization process to take place.
# The CI will ignore the zip output, using the signed binary only.
zip {
  output_path = "unused.zip"
}
