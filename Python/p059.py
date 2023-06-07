#!/usr/bin/python

# Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange).
# For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
#
# A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key.
# The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107,
# then 107 XOR 42 = 65.
#
# For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep
# the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
#
# Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than
# the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long
# password key for security, but short enough to be memorable.
#
# Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt, a file containing the
# encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the
# ASCII values in the original text.

from timeit import default_timer


class EncryptedText():

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.text = None
        self.len = 0

    def read_text(self, filename):
        try:
            with open(filename, 'r', encoding='utf-8') as fp:
                self.text = list(map(int, list(fp.readline().split(','))))
        except FileNotFoundError:
            print(f'Error while opening file {filename}')

            return -1

        self.len = len(self.text)

    def decrypt(self):
        found = 0

        for c1 in range(ord('a'), ord('z')+1):
            if found:
               break
            for c2 in range(ord('a'), ord('z')+1):
                if found:
                    break
               
                for c3 in range(ord('a'), ord('z')+1):
                    if found:
                        break

                    plain_text = [''] * self.len

                    for i in range(0, self.len-2, 3):
                        plain_text[i] = str(chr(self.text[i]^c1))
                        plain_text[i+1] = str(chr(self.text[i+1]^c2))
                        plain_text[i+2] = str(chr(self.text[i+2]^c3))

                    if i == self.len - 2:
                        plain_text[i] = str(chr(self.text[i]^c1))
                        plain_text[i+1] = str(chr(self.text[i+1]^c2))

                    if i == self.len - 1:
                        plain_text[i] = str(chr(self.text[i]^c1))

                    plain_text = ''.join(plain_text)

                    if 'the' in plain_text and 'be' in plain_text and 'to' in plain_text and 'of' in plain_text and\
                            'and' in plain_text and 'in' in plain_text and 'that' in plain_text and 'have' in plain_text:
                        found = 1

        return plain_text


def main():
    start = default_timer()

    enc_text = EncryptedText()

    if enc_text.read_text('p059_cipher.txt') == -1:
        sys.exit(1)

    plain_text = enc_text.decrypt()

    sum_ = 0

    for i in list(plain_text):
        sum_ = sum_ + ord(i)

    end = default_timer()

    print('Project Euler, Problem 59')
    print(f'Answer: {sum_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
