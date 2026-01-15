import torch
from model import AnomalyClassifier

def export_onnx():
    model = AnomalyClassifier(input_dim=5, num_classes=2)
    dummy_input = torch.randn(1, 5)

    torch.onnx.export(
        model,
        dummy_input,
        "model.onnx",
        input_names=["input"],
        output_names=["output"],
        opset_version=12
    )
    print("[INFO] Exported model → model.onnx")

if __name__ == "__main__":
    export_onnx()
