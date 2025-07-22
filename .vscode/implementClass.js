const fs = require('fs');
const path = require('path');

// Get the class name from command line arguments
const className = process.argv[2];
const outputDir = process.argv[3] || __dirname; // Default to current directory if no output directory is provided
if (!className) {
  console.error("Please provide a class name as an argument.");
  process.exit(1);
}

// Define the C++ class template in orthodox canonical form
const classTemplate = `#include "${className}.h"
    
	${className}::${className}()
	{
		//Default Constructor
	}

    ${className}::${className}(const ${className}& other)
	{
		//Copy Constructor
	}

    ${className}& ${className}::operator=(const ${className}& other)
	{
		//Copy Assignment Constructor
	}

	${className}::~${className}()
	{
		//Dstructor
	}

`;

// Define the file name and write the template to a new file
const fileName = `${className}.cpp`;
const filePath = path.join(outputDir, fileName);

fs.writeFile(filePath, classTemplate, (err) => {
  if (err) {
    console.error("Error writing file:", err);
    process.exit(1);
  }
  console.log(`C++ class ${className} generated in ${fileName}`);
});