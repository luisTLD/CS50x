import csv
import sys


def main():

    # TODO: Check for command-line usage
    arguments = sys.argv

    if len(arguments) != 3:
        print("Use ex: python dna.py databases/large.csv sequences/20.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(arguments[1], 'r') as file:
        dataLines = file.readlines()

    # TODO: Read DNA sequence file into a variable
    with open(arguments[2], 'r') as file:
        dna = file.readline().strip()

    # TODO: Find longest match of each STR in DNA sequence
    sequences = dataLines[0].strip().split(',')
    totalSeq = len(sequences)
    dnaSeqSum = [0] * (totalSeq - 1)

    for i in range (1, totalSeq):
        atualSeq = sequences[i]
        atualLen = len(atualSeq)

        index = 0;
        maxCount = 0;
        count = 0;
        while index <= len(dna) - atualLen:
            if dna[index:index + atualLen] == atualSeq:
                count += 1
                index += atualLen
            else:
                maxCount = count if count > maxCount else maxCount
                count = 0
                index += 1

        maxCount = count if count > maxCount else maxCount
        dnaSeqSum[i - 1] = maxCount

    # TODO: Check database for matching profiles
    answer = "No match"

    for i in range (1, len(dataLines)):
        person = dataLines[i].strip().split(',')
        verify = True
        for j in range(1, totalSeq):
            if int(person[j]) != dnaSeqSum[j - 1]:
                verify = False
                break

        if verify:
            answer = person[0]
            break


    print(answer)


"""
def longest_match(sequence, subsequence):
    '''Returns length of longest run of subsequence in sequence.'''

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run
"""

main()
