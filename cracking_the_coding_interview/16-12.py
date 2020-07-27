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
        def parseChild(node, s):
            if not node:
                return s
                
            s += self.tag_map[node.tag] + " "
            # print(node.tag)
            for item in node.attrib.items():
                s += self.attrib_map[item[0]] + " "
                s += item[1] + " "
            if node.text:
                s += node.text + " "

            s += "0 "

            for child in node:
                parseChild(child, s)
                
            s += "0 "
            return s


        tree = ET.parse(file_name)
        root = tree.getroot()
        # print(root.tag)
        # print(root.attrib)
        # print(root.text)
        return parseChild(root, "")


if __name__ == '__main__':
    xp = xmlParse()
    ans = xp.encodeXml('sample.xml')
    print(ans)