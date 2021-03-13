class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split(' ')
        for i in range(len(words)):
            if words[i][0].lower() in ['a','e','i','o','u']:
                words[i] += 'ma' + 'a'*(i+1)
            else:
                words[i] = words[i][1:len(words[i])] + words[i][0] + 'ma' + 'a'*(i+1)
                
        ans = ' '.join(words)
        return ans