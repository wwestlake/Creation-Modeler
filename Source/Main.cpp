#include <JuceHeader.h>
#include "MainComponent.h"
#include <creation/ui/CreationSuiteLogos.h>
#include <creation/ui/SuiteJUCEApplication.h>

class CreationModelerApplication final : public creation::ui::SuiteJUCEApplication
{
public:
    CreationModelerApplication() : SuiteJUCEApplication(creation::ui::SuiteLogoId::modeler) {}

    const juce::String getApplicationName() override { return "Creation Modeler"; }
    const juce::String getApplicationVersion() override { return "0.0.1"; }
    bool moreThanOneInstanceAllowed() override { return true; }

    void systemRequestedQuit() override
    {
        quit();
    }

protected:
    std::unique_ptr<juce::DocumentWindow> createMainWindow() override
    {
        return std::make_unique<MainWindow>(getApplicationName());
    }

private:
    class MainWindow final : public juce::DocumentWindow
    {
    public:
        explicit MainWindow(juce::String name)
            : juce::DocumentWindow(name,
                                   juce::Desktop::getInstance().getDefaultLookAndFeel()
                                       .findColour(juce::ResizableWindow::backgroundColourId),
                                   juce::DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setIcon(creation::ui::getSuiteLogoImage(creation::ui::SuiteLogoId::modeler));
            setContentOwned(new MainComponent(), true);
            centreWithSize(getWidth(), getHeight());
            setResizable(true, true);
            setVisible(true);
        }

        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }
    };
};

START_JUCE_APPLICATION(CreationModelerApplication)
