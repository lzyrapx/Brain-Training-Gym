#!/bin/bash

# Check number of arguments
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename.kt>"
    exit 1
fi

KOTLIN_FILE="$1"

# Check if file exists
if [ ! -f "$KOTLIN_FILE" ]; then
    echo "Error: File '$KOTLIN_FILE' does not exist"
    exit 1
fi

# Check if kotlinc compiler is available
if ! command -v kotlinc &> /dev/null; then
    echo "Error: kotlinc command not found, please install Kotlin compiler first"
    exit 1
fi

# Compile Kotlin file (include runtime in jar)
echo "Compiling $KOTLIN_FILE ..."
kotlinc "$KOTLIN_FILE" -include-runtime -d "${KOTLIN_FILE%.kt}.jar"
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Run the generated jar file
echo "Running ${KOTLIN_FILE%.kt}.jar ..."
java -jar "${KOTLIN_FILE%.kt}.jar"

# Optional: Delete temporary jar file (uncomment the next line to enable)
# rm "${KOTLIN_FILE%.kt}.jar"