import xml.etree.ElementTree as ET

class xmlParse:
    tag_map = {
        "family": "1",
        "person": "2"
    }

    attrib_map = {
        "firstName": "3",
        "lastName": "4",
        "state": "5"
    }

    def encodeXml(self, file_name):
        def parseChild(node):
            if node == None:
                return ""
                
            s = self.tag_map[node.tag] + " "
            for item in node.attrib.items():
                s += self.attrib_map[item[0]] + " "
                s += item[1] + " "
            s += "0 "
            if node.text:
                s += node.text.strip() + " "

            for child in node:
                encoded = parseChild(child)
                s += encoded
                
            s += "0 "
            return s

        tree = ET.parse(file_name)
        root = tree.getroot()
        return parseChild(root)


if __name__ == '__main__':
    xp = xmlParse()
    ans = xp.encodeXml('sample.xml')
    print(ans)
    print("1 4 McDowell 5 CA 0 2 3 Gayle 0 Some message 0 0.")