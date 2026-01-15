import torch
import torch.nn as nn

class AnomalyClassifier(nn.Module):
    def __init__(self, input_dim=5, num_classes=2):
        super().__init__()

        self.features = nn.Sequential(
            nn.Linear(input_dim, 16),
            nn.ReLU(),
            nn.Linear(16, 8),
            nn.ReLU()
        )

        self.classifier = nn.Linear(8, num_classes)

    def forward(self, x):
        x = self.features(x)
        x = self.classifier(x)
        return x
