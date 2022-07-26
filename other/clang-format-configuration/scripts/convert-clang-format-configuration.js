// Convert the YAML ClangFormat configuration file to the JavaScript object source code for use by Arduino IDE 2.x
// https://github.com/arduino/arduino-ide/blob/main/arduino-ide-extension/src/node/clang-formatter.ts

const fs = require("fs");
const yaml = require("js-yaml");
const util = require("util");

try {
  const inputPath = process.argv[2];
  const conversionPath = process.argv[3];
  const configurationData = yaml.load(fs.readFileSync(inputPath, "utf8"));
  fs.writeFileSync(conversionPath, util.format("%O", configurationData));
  console.log("Conversion written to", conversionPath);
} catch (e) {
  console.error(e);
  process.exitCode = 1;
}
