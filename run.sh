#!/bin/bash

# Usage:
# ./run.sh build    # build only
# ./run.sh run      # run only
# ./run.sh          # build and run (default)
# ./run.sh filename.cpp  # build and run specific file

cppname="main.cpp"  # default source file name
outname="main"      # default output file name

# Function to print error with line info
print_error() {
    echo "ERROR: $1"
    echo "At line ${BASH_LINENO[0]} in script"
    exit 1
}

# Function to check if file exists
check_file_exists() {
    if [ ! -f "$1" ]; then
        print_error "File '$1' does not exist"
    fi
}

# Check if source file parameter is provided
if [ $# -gt 1 ]; then
    cppname=$2
    check_file_exists "$cppname"
fi

# Determine action based on first argument
case $1 in
    "build")
        echo "Building $cppname..."
        check_file_exists "$cppname"
        g++ -std=c++17 -O3 -Wall -Wextra -Werror "$cppname" -o "$outname" 2>&1
        if [ $? -eq 0 ]; then
            echo "Build successful!"
        else
            print_error "Compilation failed for $cppname. Check your code for errors."
        fi
        ;;
    "run")
        echo "Running program..."
        if [ -f "./$outname" ]; then
            ./"$outname"
            if [ $? -ne 0 ]; then
                print_error "Program execution failed with exit code $?"
            fi
        else
            print_error "Executable '$outname' not found. Please build first with: ./run.sh build"
        fi
        ;;
    "")
        echo "Building and running..."
        check_file_exists "$cppname"
        g++ -std=c++17 -O3 -Wall -Wextra -Werror "$cppname" -o "$outname" 2>&1
        if [ $? -eq 0 ]; then
            echo "Build successful, starting program..."
            ./"$outname"
            if [ $? -ne 0 ]; then
                print_error "Program execution failed with exit code $?"
            fi
        else
            print_error "Compilation failed for $cppname. Check your code for errors."
        fi
        ;;
    *)
        # If first argument is not build/run, treat it as source filename
        cppname=$1
        check_file_exists "$cppname"
        echo "Building and running $cppname..."
        g++ -std=c++17 -O3 -Wall -Wextra -Werror "$cppname" -o "$outname" 2>&1
        if [ $? -eq 0 ]; then
            echo "Build successful, starting program..."
            ./"$outname"
            if [ $? -ne 0 ]; then
                print_error "Program execution failed with exit code $?"
            fi
        else
            print_error "Compilation failed for $cppname. Check your code for errors."
        fi
        ;;
esac

echo "Operation completed successfully."