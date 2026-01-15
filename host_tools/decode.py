def decode(line):
    if line.startswith("ANOMALY:"):
        try:
            return int(line.split(":")[1])
        except:
            return None
    return None
