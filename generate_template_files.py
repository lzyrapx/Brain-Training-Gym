# generate_template_files.py

import os

def read_template_from_file(template_file="template.cc"):
    """
    Read template content from a file. If the file doesn't exist,
    return a default template.
    """
    if os.path.exists(template_file):
        try:
            with open(template_file, 'r') as f:
                return f.read()
        except Exception as e:
            print(f"Warning: Could not read template file: {e}")
            print("Using default template instead.")
    
    # Default template if file doesn't exist or can't be read
    raise "template file doesn't exist or can't be read"

def read_execute_script_from_file(template_file="run.sh"):
    """
    Read execute script from a file. If the file doesn't exist,
    return a default template.
    """
    if os.path.exists(template_file):
        try:
            with open(template_file, 'r') as f:
                return f.read()
        except Exception as e:
            print(f"Warning: Could not read execute script file: {e}")
            print("Using default execute script instead.")
    
    # Default execute script if file doesn't exist or can't be read
    raise "execute script file doesn't exist or can't be read"

def generate_files(last_letter, output_path):
    # Convert input to uppercase
    last_letter = last_letter.upper()
    
    # Validate input
    if len(last_letter) != 1 or not last_letter.isalpha():
        print("Error: Please enter a single letter (A-Z)")
        return
    
    # Check and create output directory if needed
    if output_path and not os.path.exists(output_path):
        try:
            os.makedirs(output_path)
            print(f"Created directory: {output_path}")
        except OSError as e:
            print(f"Failed to create directory: {e}")
            return
    
    # Generate filenames from A to the specified letter
    start_char = 'A'
    end_char = last_letter
    
    filenames = []
    current_char = start_char
    while current_char <= end_char:
        filenames.append(f"{current_char}.cc")
        current_char = chr(ord(current_char) + 1)
    
    # Read template content
    template = read_template_from_file()
    
    # Generate files
    for filename in filenames:
        # Build full file path
        if output_path:
            full_path = os.path.join(output_path, filename)
        else:
            full_path = filename
        
        with open(full_path, 'w') as f:
            f.write(template)
        print(f"Generated {full_path}")
    
    print(f"\nSuccessfully generated {len(filenames)} files from A.cc to {last_letter}.cc!")
    if output_path:
        print(f"Files saved to: {os.path.abspath(output_path)}")

    # Read execute script content
    execute_script = read_execute_script_from_file()
    
    # create execute script file test.sh
    full_path = os.path.join(output_path, "test.sh")
    with open(full_path, 'w') as f:
        f.write(execute_script)
        print(f"Generated {full_path}")
    
    full_path = os.path.join(output_path, "in.txt")
    # create input file in.txt
    with open(full_path, 'w') as f:
        f.write("")
        print(f"Generated {full_path}")

if __name__ == "__main__":
    # Get user input
    last_letter = input("Enter the last letter (e.g., F will generate A.cc to F.cc): ")
    output_path = input("Enter output path (leave empty for current directory): ").strip()
    
    # If user entered a path but it's empty string, set to None
    if not output_path:
        output_path = None
    
    # Generate files
    generate_files(last_letter, output_path)