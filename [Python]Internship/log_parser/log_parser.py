import argparse
import os
import glob


def get_keywords(keywords_txt):  # Get Keywords from (file) keywords_txt, delimited by a new line
    with open(keywords_txt) as file:  # Open file from path in parameters
        list_of_keywords = [line.rstrip('\n') for line in file]  # Populate list from keywords.txt removing newline char
    return list_of_keywords  # Return the populated list of keywords. EXAMPLE: ['ERROR','WARN', 'INFO'...]


def parse_log(path, list_of_keywords):  # [path] is the direct path including filename,[keyword] is a list of keywords
    print("\nLocation: " + path)  # Display the log file/path to search for keywords
    file = open(path)  # Open log file/path
    line = file.readline()  # Read first line
    line_number = 1  # Initialize line counter to the first line

    while line:  # While there's still lines with content in the file
        for keyword in list_of_keywords:  # For each keyword in the list of keywords
            if keyword in line:  # If the line contains the keyword in the file
                print("Line #" + str(line_number) + " " + line)  # Display line number + the line a keyword was found at
        line = file.readline()  # Move to to next line
        line_number += 1  # Increment line count
    file.close()  # Close log file after reading all of its contents


def main():
    parser = argparse.ArgumentParser(description='Search Key.')  # Container to hold arguments
    parser.add_argument('-p', '-path', type=str, help='Log File To Parse.')  # -p flag indicates path/dir of log file/s
    args = parser.parse_args()
    list_of_keywords = get_keywords("keywords.txt")  # Load list of keywords from this file/path

    os.system('clear')
    print("\n\nKeywords List:")
    print(list_of_keywords)

    if os.path.isdir(args.p):  # If the path the user provided is a directory instead a file
        print("\nStatus: Directory")  # Indicate its a directory
        directories = glob.glob(args.p + "*.log", recursive=True)  # Load all files in the directory to a list
        for directory in directories:  # For each file in the list of user specified directory
            parse_log(directory, list_of_keywords)  # Parse and print to console
    elif os.path.isfile(args.p):  # else If its a file
        print("\nStatus: File")  # Indicate its a file
        parse_log(args.p, list_of_keywords)  # Parse and print to console


if __name__ == "__main__":
    main()

'''

To Run The Script:
- Have the file keywords.txt in the same folder as the script
- Open and type the keywords as you expect them to appear into Keywords.txt file and close it
- run the script with designated path

python3 -p [path to the log file or a directory full of log files to search for keyword/s in keywords.txt]

-Example Usage
python3 log_parser.py -p /Users/user/Desktop/logfiles/pennybot-14f66f_1099d19a-20f4-4344-bc39-21eb18f86097/

'''
