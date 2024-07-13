class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        path = re.sub('/+', '/', path)
        
        if(path.startswith('/')):
            path = path[1:]

        strList = path.split('/')
        
        i = 0
        while i < len(strList):
            if strList[i] == '..':
                if i > 0:
                    strList.pop(i)
                    strList.pop(i-1)
                    i-=1
                else:
                    strList.pop(i)
            elif strList[i] == '.' or strList[i] == '':
                strList.pop(i)
            else:
                i+=1

        path = '/' + '/'.join(strList)

        if path.endswith('/'):
            path = path[:-1]

        if path == '':
            path = '/'

        return path
