#ifndef HTKFORCEDALIGNER_H
#define HTKFORCEDALIGNER_H

#include <QObject>
#include "PraalineCore/Annotation/IntervalTier.h"
#include "PraalineASR/PraalineASR_Global.h"
#include "PraalineASR/SpeechToken.h"
#include "PraalineASR/ForcedAligner.h"

namespace Praaline {
namespace ASR {

struct HTKForcedAlignerData;

class PRAALINE_ASR_SHARED_EXPORT HTKForcedAligner : public ForcedAligner
{
    Q_OBJECT
public:
    explicit HTKForcedAligner(QObject *parent = nullptr);
    ~HTKForcedAligner() override;

    bool alignTokens(const QString &waveFilepath, RealTime timeFrom, RealTime timeTo,
                     Praaline::Core::IntervalTier *tierTokens, int &indexFrom, int &indexTo,
                     bool insertLeadingAndTrailingPauses,
                     QList<Praaline::Core::Interval *> &outPhonesList, QString &outAlignerOutput) override;

private:
    HTKForcedAlignerData *d;

    QString translatePhonemes(const QString &input);
    bool createFilesDCTandLAB(const QString &filenameBase, QList<SpeechToken> &atokens);
    bool runAligner(const QString &filenameBase, QList<SpeechToken> &atokens, QList<SpeechPhone> &aphones,
                    QString &alignerOutput);

    // Encode UTF entities (e.g. accented characters) to Latin1 for LAB files
    QString encodeEntities(const QString &src, const QString &force = QString());
    QString decodeEntities(const QString &src);

    void cleanUpTempFiles(const QString &waveResampledBase);
};

} // namespace ASR
} // namespace Praaline

#endif // HTKFORCEDALIGNER_H
